
/** $VER: MusicKeyboard.cpp (2023.12.24) P. Stuer **/

#include <CppCoreCheck/Warnings.h>
#pragma warning(disable: 5045 5262 ALL_CPPCORECHECK_WARNINGS)

#include "framework.h"

#include "MusicKeyboard.h"
#include "MusicKeyboardUIElement.h"

#pragma hdrstop

namespace foo_vis_midi
{
extern MusicKeyboardWindow * _This;

#pragma region IMusicKeyboard

[[nodiscard]] void MusicKeyboard::Initialize(uint32_t interfaceVersion) noexcept
{
    if (_This)
        _This->Initialize(interfaceVersion);
}

[[nodiscard]] void MusicKeyboard::ProcessMessage(uint32_t message, uint32_t timestamp) noexcept
{
    if (_This)
        _This->ProcessMessage(message, timestamp);
}

[[nodiscard]] void MusicKeyboard::SetPosition(uint32_t position) noexcept
{
    if (_This)
        _This->SetPosition(position);
}

#pragma endregion
}
