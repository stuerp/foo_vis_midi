
/** $VER: Component.cpp (2023.12.24) P. Stuer **/

#include "pch.h"

#include <CppCoreCheck\Warnings.h>

#pragma warning(disable: 4625 4626 4710 4711 5045 ALL_CPPCORECHECK_WARNINGS)

#include <sdk\componentversion.h>

#include "Resources.h"

#pragma hdrstop

namespace
{
    #pragma warning(disable: 4265 5026 5027 26433 26436 26455)
    DECLARE_COMPONENT_VERSION
    (
        STR_COMPONENT_NAME,
        STR_COMPONENT_VERSION,
        STR_COMPONENT_BASENAME " " STR_COMPONENT_VERSION "\n"
            STR_COMPONENT_COPYRIGHT "\n"
            "\n"
            STR_COMPONENT_DESCRIPTION "\n"
            STR_COMPONENT_COMMENTS "\n"
            "\n"
            "Built with foobar2000 SDK " TOSTRING(FOOBAR2000_SDK_VERSION) "\n"
            "on " __DATE__ " " __TIME__ "."
    )
    VALIDATE_COMPONENT_FILENAME(STR_COMPONENT_FILENAME)
}
