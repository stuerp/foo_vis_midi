
/** $VER: Key.h (2026.04.22) P. Stuer **/

#pragma once

#include <CppCoreCheck\Warnings.h>
#pragma warning(disable: 5045 5262 ALL_CPPCORECHECK_WARNINGS)

const float WhiteKeyWidth = 23.5f; // mm
const float WhiteKeyHeight = 150.0f; // mm

const float BlackKeyWidth = 13.7f; // mm
const float BlackKeyHeight = 90.0f; // mm

/// <summary>
/// Implements a base class for a keyboard key.
/// </summary>
#pragma warning(disable: 4820)
class key_t
{
public:
    key_t(ID2D1PathGeometry * geometry) : _Geometry(geometry), _IsDown(false) { }

    key_t(const key_t &) = delete;
    key_t & operator=(const key_t &) = delete;
    key_t(key_t &&) = delete;
    key_t & operator=(key_t &&) = delete;

    virtual ~key_t()
    {
    };

    virtual HRESULT Measure(D2D1_SIZE_F& size) const noexcept = 0;
    virtual HRESULT Render(ID2D1HwndRenderTarget * renderTarget, ID2D1Brush * whiteBrush, ID2D1Brush * blackBrush, ID2D1Brush * pushedBrush, float& dx) const noexcept = 0;

    float GetHeight() const noexcept { return WhiteKeyHeight; }

    void Push() noexcept { _IsDown = true; }
    void Release() noexcept { _IsDown = false; }

protected:
    ID2D1PathGeometry * _Geometry;
    bool _IsDown;
};
#pragma warning(default: 4820)

/// <summary>
/// Implements a white, left keyboard key.
/// </summary>
#pragma warning(disable: 4820)
class left_white_key_t : public key_t
{
public:
    left_white_key_t(ID2D1PathGeometry * geometry) : key_t(geometry) { }

    left_white_key_t(const left_white_key_t &) = delete;
    left_white_key_t & operator=(const left_white_key_t &) = delete;
    left_white_key_t(left_white_key_t &&) = delete;
    left_white_key_t & operator=(left_white_key_t &&) = delete;

    ~left_white_key_t() final { };

    virtual HRESULT Measure(D2D1_SIZE_F& size) const noexcept
    {
        size = { WhiteKeyWidth, WhiteKeyHeight };

        return S_OK;
    }

    virtual HRESULT Render(ID2D1HwndRenderTarget * renderTarget, ID2D1Brush * whiteBrush, ID2D1Brush * blackBrush, ID2D1Brush * pushedBrush, float& dx) const noexcept final;
};
#pragma warning(default: 4820)

/// <summary>
/// Implements a white, middle keyboard key.
/// </summary>
#pragma warning(disable: 4820)
class middle_white_key_t : public key_t
{
public:
    middle_white_key_t(ID2D1PathGeometry * geometry) : key_t(geometry) { }

    middle_white_key_t(const middle_white_key_t &) = delete;
    middle_white_key_t & operator=(const middle_white_key_t &) = delete;
    middle_white_key_t(middle_white_key_t &&) = delete;
    middle_white_key_t & operator=(middle_white_key_t &&) = delete;

    ~middle_white_key_t() final { };

    virtual HRESULT Measure(D2D1_SIZE_F& size) const noexcept
    {
        size = { WhiteKeyWidth, WhiteKeyHeight };

        return S_OK;
    }

    virtual HRESULT Render(ID2D1HwndRenderTarget * renderTarget, ID2D1Brush * whiteBrush, ID2D1Brush * blackBrush, ID2D1Brush * pushedBrush, float& dx) const noexcept final;
};
#pragma warning(default: 4820)

/// <summary>
/// Implements a white, right keyboard key.
/// </summary>
#pragma warning(disable: 4820)
class right_white_key_t : public key_t
{
public:
    right_white_key_t(ID2D1PathGeometry * geometry) : key_t(geometry) { }

    right_white_key_t(const right_white_key_t &) = delete;
    right_white_key_t & operator=(const right_white_key_t &) = delete;
    right_white_key_t(right_white_key_t &&) = delete;
    right_white_key_t & operator=(right_white_key_t &&) = delete;

    ~right_white_key_t() final { };

    virtual HRESULT Measure(D2D1_SIZE_F& size) const noexcept
    {
        size = { WhiteKeyWidth, WhiteKeyHeight };

        return S_OK;
    }

    virtual HRESULT Render(ID2D1HwndRenderTarget * renderTarget, ID2D1Brush * whiteBrush, ID2D1Brush * blackBrush, ID2D1Brush * pushedBrush, float& dx) const noexcept final;
};
#pragma warning(default: 4820)

/// <summary>
/// Implements a black keyboard key.
/// </summary>
#pragma warning(disable: 4820)
class black_key_t : public key_t
{
public:
    black_key_t() : key_t(nullptr) { };

    black_key_t(const black_key_t &) = delete;
    black_key_t & operator=(const black_key_t &) = delete;
    black_key_t(black_key_t &&) = delete;
    black_key_t & operator=(black_key_t &&) = delete;

    ~black_key_t() final { };

    virtual HRESULT Measure(D2D1_SIZE_F& size) const noexcept
    {
        size = { 0.f, 0.f };

        return S_OK;
    }

    virtual HRESULT Render(ID2D1HwndRenderTarget * renderTarget, ID2D1Brush * whiteBrush, ID2D1Brush * blackBrush, ID2D1Brush * pushedBrush, float& dx) const noexcept final;

private:
    const D2D1_RECT_F _Rect = { 0, 0, BlackKeyWidth, BlackKeyHeight };
};
#pragma warning(default: 4820)

/// <summary>
/// Implements a white keyboard key.
/// </summary>
#pragma warning(disable: 4820)
class white_key_t : public key_t
{
public:
    white_key_t() : key_t(nullptr) { };

    white_key_t(const white_key_t &) = delete;
    white_key_t & operator=(const white_key_t &) = delete;
    white_key_t(white_key_t &&) = delete;
    white_key_t & operator=(white_key_t &&) = delete;

    ~white_key_t() final { };

    virtual HRESULT Measure(D2D1_SIZE_F& size) const noexcept
    {
        size = { WhiteKeyWidth, WhiteKeyHeight };

        return S_OK;
    }

    virtual HRESULT Render(ID2D1HwndRenderTarget * renderTarget, ID2D1Brush * whiteBrush, ID2D1Brush * blackBrush, ID2D1Brush * pushedBrush, float& dx) const noexcept final;

private:
    const D2D1_RECT_F _Rect = { 0, 0, WhiteKeyWidth, WhiteKeyHeight };
};
#pragma warning(default: 4820)
