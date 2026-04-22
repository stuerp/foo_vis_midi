
/** $VER: Resources.h (2026.04.22) P. Stuer **/

#pragma once

#define TOSTRING_IMPL(x) #x
#define TOSTRING(x) TOSTRING_IMPL(x)

#define NUM_FILE_MAJOR              0
#define NUM_FILE_MINOR              2
#define NUM_FILE_PATCH              0
#define NUM_FILE_PRERELEASE         0

#define NUM_PRODUCT_MAJOR           0
#define NUM_PRODUCT_MINOR           2
#define NUM_PRODUCT_PATCH           0
#define NUM_PRODUCT_PRERELEASE      0

/** Component specific **/

#define STR_COMPONENT_NAME          "MIDI Visualizer"
#define STR_COMPONENT_VERSION       TOSTRING(NUM_FILE_MAJOR) "." TOSTRING(NUM_FILE_MINOR) "." TOSTRING(NUM_FILE_PATCH) "." TOSTRING(NUM_FILE_PRERELEASE)
#define STR_COMPONENT_BASENAME      "foo_vis_midi"
#define STR_COMPONENT_FILENAME      STR_COMPONENT_BASENAME ".dll"
#define STR_COMPONENT_COMPANY_NAME  ""
#define STR_COMPONENT_COPYRIGHT     "Copyright (c) 2023-2026 P. Stuer. All rights reserved."
#define STR_COMPONENT_COMMENTS      ""
#define STR_COMPONENT_DESCRIPTION   "A MIDI message visualizer for foobar2000"
#define STR_COMPONENT_URL           "https://github.com/stuerp/" STR_COMPONENT_BASENAME

/** Generic **/

#define STR_COMPANY_NAME            TEXT(STR_COMPONENT_COMPANY_NAME)
#define STR_INTERNAL_NAME           TEXT(STR_COMPONENT_NAME)
#define STR_COMMENTS                TEXT(STR_COMPONENT_COMMENTS)
#define STR_COPYRIGHT               TEXT(STR_COMPONENT_COPYRIGHT)

#define STR_FILE_NAME               TEXT(STR_COMPONENT_FILENAME)
#define STR_FILE_VERSION            TEXT(STR_COMPONENT_VERSION)
#define STR_FILE_DESCRIPTION        TEXT(STR_COMPONENT_DESCRIPTION)

#define STR_PRODUCT_NAME            STR_INTERNAL_NAME
#define STR_PRODUCT_VERSION         TEXT(TOSTRING(NUM_PRODUCT_MAJOR)) TEXT(".") TEXT(TOSTRING(NUM_PRODUCT_MINOR)) TEXT(".") TEXT(TOSTRING(NUM_PRODUCT_PATCH)) TEXT(".") TEXT(TOSTRING(NUM_PRODUCT_PRERELEASE))

#define STR_ABOUT_NAME              STR_INTERNAL_NAME
#define STR_ABOUT_WEB               TEXT(STR_COMPONENT_URL)
#define STR_ABOUT_EMAIL             TEXT("mailto:peter.stuer@outlook.com")

#define IDD_PREFERENCES             101
