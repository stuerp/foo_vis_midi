
/** $VER: main.cpp (2023.01.09) P. Stuer **/

#include <CppCoreCheck/Warnings.h>
#pragma warning(disable: 5045 5262 ALL_CPPCORECHECK_WARNINGS)

#include "framework.h"

#include <sdk/componentversion.h>

#pragma hdrstop

namespace
{
    #pragma warning(push)
    #pragma warning(disable: 4265 4625 4626 5026 5027 26433 26436 26455)
    DECLARE_COMPONENT_VERSION
    (
        STR_COMPONENT_NAME,
        STR_COMPONENT_VERSION,
        STR_COMPONENT_FILENAME " " STR_COMPONENT_VERSION "\n"
            "Copyright (c) 2023 LionTech. All rights reserved.\n"
            "Written by P. Stuer\n"
            "\n"
            "A visualizer for MIDI messages\n"
            "\n"
            "Build with foobar2000 SDK " TOSTRING(FOOBAR2000_SDK_VERSION) "\n"
            "on " __DATE__ " " __TIME__ "."
    );
    #pragma warning(pop)

    VALIDATE_COMPONENT_FILENAME(STR_COMPONENT_FILENAME);
}
