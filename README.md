
# foo_vis_midi

[foo_vis_midi](https://github.com/stuerp/foo_vis_midi/releases) is a [foobar2000](https://www.foobar2000.org/) component to visualize MIDI events.

## Features

* Displays the notes played by the foo_midi component on a music keyboard.

## Requirements

* Tested on Microsoft Windows 10 and later.
* [foobar2000](https://www.foobar2000.org/download) v2.0 or later (32 or 64-bit). ![foobar2000](https://www.foobar2000.org/button-small.png)
* [foo_midi](https://github.com/stuerp/foo_midi/releases) v2.9.2 or later.

## Getting started

### Installation

* Double-click `foo_vis_midi.fbk2-component`.

or

* Import `foo_vis_midi.fbk2-component` into foobar2000 using the "*File / Preferences / Components / Install...*" menu item.

## Developing

To build the code you need:

* [Microsoft Visual Studio 2022 Community Edition](https://visualstudio.microsoft.com/downloads/) or later
* [foobar2000 SDK](https://www.foobar2000.org/SDK) 2023-09-23
* [Windows Template Library (WTL)](https://github.com/Win32-WTL/WTL) 10.0.10320

To create the deployment package you need:

* [PowerShell 7.2](https://github.com/PowerShell/PowerShell) or later

### Setup

Create the following directory structure:

    3rdParty
        WTL10_10320
    bin
        x86
    foo_vis_midi
    out
    sdk

* `3rdParty/WTL10_10320` contains WTL 10.0.10320.
* `bin` contains a portable version of foobar2000 64-bit for debugging purposes.
* `bin/x86` contains a portable version of foobar2000 32-bit for debugging purposes.
* `foo_vis_midi` contains the [Git](https://github.com/stuerp/foo_vis_midi) repository.
* `out` receives a deployable version of the component.
* `sdk` contains the foobar2000 SDK.

### Building

Open `foo_vis_midi.sln` with Visual Studio and build the solution.

### Packaging

To create the component first build the x86 configuration and next the x64 configuration.

## Change Log

v0.1.0, 2023-12-25, *"Scratchin' the itch"*

* Initial release.

## Acknowledgements / Credits

* Peter Pawlowski for the [foobar2000](https://www.foobar2000.org/) audio player. ![foobar2000](https://www.foobar2000.org/button-small.png)

## Reference Material

### foobar2000

  * [foobar2000 Development](https://wiki.hydrogenaud.io/index.php?title=Foobar2000:Development:Overview)

### Windows User Interface

  * [Desktop App User Interface](https://learn.microsoft.com/en-us/windows/win32/windows-application-ui-development)
  * [Windows User Experience Interaction Guidelines](https://learn.microsoft.com/en-us/windows/win32/uxguide/guidelines)
  * [Windows Controls](https://learn.microsoft.com/en-us/windows/win32/controls/window-controls)
  * [Control Library](https://learn.microsoft.com/en-us/windows/win32/controls/individual-control-info)
  * [Resource-Definition Statements](https://learn.microsoft.com/en-us/windows/win32/menurc/resource-definition-statements)
  * [Visuals, Layout](https://learn.microsoft.com/en-us/windows/win32/uxguide/vis-layout)

## Links

* Home page: [https://github.com/stuerp/foo_vis_midi](https://github.com/stuerp/foo_vis_midi)
* Repository: [https://github.com/stuerp/foo_vis_midi.git](https://github.com/stuerp/foo_vis_midi.git)
* Issue tracker: [https://github.com/stuerp/foo_vis_midi/issues](https://github.com/stuerp/foo_vis_midi/issues)

## License

![License: MIT](https://img.shields.io/badge/license-MIT-yellow.svg)
