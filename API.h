
/** $VER: API.h (2026.04.22) P. Stuer **/

#pragma once

#include <CppCoreCheck\Warnings.h>

#pragma warning(disable: 4514 5045 5262 ALL_CPPCORECHECK_WARNINGS)

#include <sdk\foobar2000-lite.h>

namespace foo_vis_midi
{
    const uint32_t InterfaceVersion = 1;

    class NOVTABLE IMusicKeyboard : public service_base
    {
    public:
        [[nodiscard]] virtual void Initialize(uint32_t version) = 0;

        // Processes a MIDI message.
        [[nodiscard]] virtual void ProcessMessage(uint32_t, uint32_t) = 0;

        // Sets the position of the first sample of the current chunk.
        [[nodiscard]] virtual void SetPosition(uint32_t) = 0;

        FB2K_MAKE_SERVICE_INTERFACE(IMusicKeyboard, service_base);
    };

    DECLARE_CLASS_GUID(IMusicKeyboard, 0x527da15c, 0x5125, 0x4ba3, 0x99, 0x5d, 0xb8, 0x22, 0x98, 0x08, 0x41, 0x50);

    class NOVTABLE IAPI : public service_base
    {
    public:
        // Gets a MusicKeyboard object.
        virtual IMusicKeyboard::ptr GetMusicKeyboard() const = 0;

        FB2K_MAKE_SERVICE_INTERFACE_ENTRYPOINT(IAPI)
    };

    DECLARE_CLASS_GUID(IAPI, 0x32166e94, 0xdb9f, 0x4a63, 0xa9, 0x37, 0x85, 0x36, 0xb2, 0x06, 0x51, 0x70);

    PFC_DECLARE_EXCEPTION(foo_vis_midi_exception, pfc::exception, "foo_vis_midi error");
}
