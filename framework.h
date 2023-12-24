
/** $VER: framework.h (2023.01.15) P. Stuer **/

#pragma once

#define TOSTRING_IMPL(x) #x
#define TOSTRING(x) TOSTRING_IMPL(x)

#include <SDKDDKVer.h>

#include <sdk/foobar2000-lite.h>

#define WIN32_LEAN_AND_MEAN     // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <strsafe.h>

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <math.h>

#include <algorithm>
#include <memory>
#include <vector>

#include "Resources.h"
#include "API.h"
/*
template<class Interface>
inline void SafeRelease(Interface ** interfaceToRelease)
{
    if (*interfaceToRelease)
    {
        (*interfaceToRelease)->Release();

        (*interfaceToRelease) = nullptr;
    }
}
*/