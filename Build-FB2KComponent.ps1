<#
.SYNOPSIS
    Builds the foobar2000 component package.
.DESCRIPTION
    This script will be executed unconditionally during the Post-build step. It copies all the necessary files to an output directory and creates the zip archive.
.EXAMPLE
    C:\PS> .\Build-FB2KComponent.ps1
.OUTPUTS
    *.fb2k-component
#>

[CmdletBinding()]
param
(
    [parameter(Mandatory, HelpMessage='Target Name')]
        [string] $TargetName,
    [parameter(Mandatory, HelpMessage='Target File Name')]
        [string] $TargetFileName,
    [parameter(Mandatory, HelpMessage='Platform')]
        [string] $Platform,
    [parameter(Mandatory, HelpMessage='OutputPath')]
        [string] $OutputPath
)

#Requires -Version 7.2

Set-StrictMode -Version Latest;
Set-PSDebug -Strict; # Equivalent of VBA "Option Explicit".

$ErrorActionPreference = 'Stop';

$PSStyle.OutputRendering = [System.Management.Automation.OutputRendering]::PlainText;

# Note: The working directory is the solution directory.

function Install-Component
{
    if (Test-Path -Path "../bin")
    {
        # Install the 64-bit component if there is one.
        if (Test-Path -Path $PackagePath64)
        {
            Write-Host "Installing component in foobar2000 64-bit...";

            $ProfilePath = "../bin/profile/user-components-x64/$TargetName";

            if (!(Test-Path -Path $ProfilePath))
            {
                Write-Host "Creating output directory `"$ProfilePath`"...";
                $null = New-Item -Path '../bin/profile/user-components-x64/' -Name "$TargetName" -ItemType 'directory';
            }

            Copy-Item "$PackagePath64/*" -Destination $ProfilePath -Force;
        }
    }

    if (Test-Path -Path "../bin/x86")
    {
        # Install the 32-bit component if there is one.
        if (Test-Path -Path $PackagePath86)
        {
            Write-Host "Installing component in foobar2000 32-bit...";

            $ProfilePath = "../bin/x86/profile/user-components/$TargetName";

            if (!(Test-Path -Path $ProfilePath))
            {
                Write-Host "Creating output directory `"$ProfilePath`"...";
                $null = New-Item -Path '../bin/x86/profile/user-components/' -Name "$TargetName" -ItemType 'directory';
            }

            Copy-Item "$PackagePath86/*" -Exclude "x64" -Destination $ProfilePath -Force;
        }
    }
}

Write-Host "Building package `"$TargetName`" for platform `"$Platform`"...";

if ($Platform -eq 'Win32')
{
    $Platform = 'x86';
}

$PackagePath64 = "../out/$TargetName/x64";
$PackagePath86 = "../out/$TargetName";

$Files = @(
    $TargetFileName
);

if ($Platform -eq 'x64')
{
    if (!(Test-Path -Path $PackagePath64))
    {
        Write-Host "Creating output directory `"$PackagePath64`"...";
        $null = New-Item -Path '../out/' -Name "$TargetName/x64" -ItemType 'directory';
    }

    if (Test-Path -Path "$OutputPath/$TargetFileName")
    {
        $Files | ForEach-Object {
            Write-Host "Copying $_ to `"$PackagePath86`"...";

            Copy-Item "$OutputPath/$_" -Destination "$PackagePath64";
        }
    }

    Install-Component;
}
elseif ($Platform -eq 'x86')
{
    if (!(Test-Path -Path $PackagePath86))
    {
        Write-Host "Creating output directory `"$PackagePath86`"...";
        $null = New-Item -Path '../out/' -Name "$TargetName" -ItemType 'directory';
    }

    if (Test-Path -Path "$OutputPath/$TargetFileName")
    {
        $Files | ForEach-Object {
            Write-Host "Copying $_ to `"$PackagePath86`"...";

            Copy-Item "$OutputPath/$_" -Destination "$PackagePath86";
        }
    }

    Install-Component;
}
else
{
    Write-Host "Unknown platform: $Platform";
    exit;
}

Compress-Archive -Force -Path ../out/$TargetName/* -DestinationPath ../out/$TargetName.fb2k-component;

Write-Host "Done.";
