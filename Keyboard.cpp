
/** $VER: Keyboard.cpp (2023.01.15) P. Stuer **/

#include "pch.h"

#include "Keyboard.h"
#include "Key.h"

#pragma hdrstop

/// <summary>
/// Initializes a new instance of the class.
/// </summary>
keyboard_t::keyboard_t() : _Width(0.f)
{
    SetScale(1.0f);
}

/// <summary>
/// Deletes this instance of the class.
/// </summary>
keyboard_t::~keyboard_t()
{
    Dispose();
}

/// <summary>
/// Renders the object.
/// </summary>
HRESULT keyboard_t::Render(ID2D1HwndRenderTarget * renderTarget, float x, float y) const noexcept
{
    for (auto & Key : _Keys)
    {
        float dx;

        renderTarget->SetTransform(_ScaleMatrix * D2D1::Matrix3x2F::Translation(x, y));

        Key->Render(renderTarget, _WhiteBrush, _BlackBrush, _PushedBrush, dx);

        x += dx * _ScaleMatrix.m11;
    }

    return S_OK;
}

/// <summary>
/// Gets the width of the keyboard.
/// </summary>
float keyboard_t::MeasureWidth() const noexcept
{
    float Width = 0.f;

    for (auto & Key : _Keys)
    {
        D2D1_SIZE_F KeySize;

        Key->Measure(KeySize);

        Width += KeySize.width + 1.f;
    }

    return Width;
}

/// <summary>
/// Creates the device-independent resources.
/// </summary>
HRESULT keyboard_t::CreateDeviceIndependentResources(ID2D1Factory * d2DFactory) noexcept
{
    // Create the left white key.
    HRESULT hr = d2DFactory->CreatePathGeometry(&_LeftWhitePathGeometry);

    if (SUCCEEDED(hr))
    {
        CComPtr<ID2D1GeometrySink> gs;

        hr = _LeftWhitePathGeometry->Open(&gs);

        if (SUCCEEDED(hr))
        {
            gs->SetFillMode(D2D1_FILL_MODE_WINDING);

            gs->BeginFigure(D2D1::Point2F(0, 0), D2D1_FIGURE_BEGIN_FILLED);

            const D2D1_POINT_2F Points[5] =
            {
               D2D1::Point2F(WhiteKeyWidth - BlackKeyWidth / 2, 0),
               D2D1::Point2F(WhiteKeyWidth - BlackKeyWidth / 2, BlackKeyHeight),
               D2D1::Point2F(WhiteKeyWidth, BlackKeyHeight),
               D2D1::Point2F(WhiteKeyWidth, WhiteKeyHeight),
               D2D1::Point2F( 0, WhiteKeyHeight), 
            };

            gs->AddLines(Points, ARRAYSIZE(Points));
            gs->EndFigure(D2D1_FIGURE_END_CLOSED);

            hr = gs->Close();
        }
    }

    // Create the middle white key.
    hr = d2DFactory->CreatePathGeometry(&_MiddleWhitePathGeometry);

    if (SUCCEEDED(hr))
    {
        CComPtr<ID2D1GeometrySink> gs;

        hr = _MiddleWhitePathGeometry->Open(&gs);

        if (SUCCEEDED(hr))
        {
            gs->SetFillMode(D2D1_FILL_MODE_WINDING);

            gs->BeginFigure(D2D1::Point2F(BlackKeyWidth / 2, 0), D2D1_FIGURE_BEGIN_FILLED);

            const D2D1_POINT_2F Points[] =
            {
               D2D1::Point2F(WhiteKeyWidth - (BlackKeyWidth / 2),   0),
               D2D1::Point2F(WhiteKeyWidth - (BlackKeyWidth / 2), BlackKeyHeight),
               D2D1::Point2F(WhiteKeyWidth, BlackKeyHeight),
               D2D1::Point2F(WhiteKeyWidth, WhiteKeyHeight),
               D2D1::Point2F( 0, WhiteKeyHeight),
               D2D1::Point2F( 0, BlackKeyHeight),
               D2D1::Point2F(BlackKeyWidth / 2, BlackKeyHeight),
            };

            gs->AddLines(Points, ARRAYSIZE(Points));
            gs->EndFigure(D2D1_FIGURE_END_CLOSED);

            hr = gs->Close();
        }
    }

    // Create the right white key.
    hr = d2DFactory->CreatePathGeometry(&_RightWhitePathGeometry);

    if (SUCCEEDED(hr))
    {
        CComPtr<ID2D1GeometrySink> gs;

        hr = _RightWhitePathGeometry->Open(&gs);

        if (SUCCEEDED(hr))
        {
            gs->SetFillMode(D2D1_FILL_MODE_WINDING);

            gs->BeginFigure(D2D1::Point2F(BlackKeyWidth / 2, 0), D2D1_FIGURE_BEGIN_FILLED);

            const D2D1_POINT_2F Points[5] =
            {
               D2D1::Point2F(WhiteKeyWidth, 0),
               D2D1::Point2F(WhiteKeyWidth, WhiteKeyHeight),
               D2D1::Point2F(0, WhiteKeyHeight),
               D2D1::Point2F(0, BlackKeyHeight),
               D2D1::Point2F(BlackKeyWidth / 2, BlackKeyHeight), 
            };

            gs->AddLines(Points, ARRAYSIZE(Points));
            gs->EndFigure(D2D1_FIGURE_END_CLOSED);

            hr = gs->Close();
        }
    }
 
    // Create the keys. Middle C = MIDI 60 = Index = 39.
    _Keys.reserve(88);

    _Keys.push_back(make_unique<left_white_key_t>(_LeftWhitePathGeometry));
    _Keys.push_back(make_unique<black_key_t>());
    _Keys.push_back(make_unique<right_white_key_t>(_RightWhitePathGeometry));

    for (size_t i = 0; i < 7; ++i)
    {
        _Keys.push_back(make_unique<left_white_key_t>(_LeftWhitePathGeometry));
        _Keys.push_back(make_unique<black_key_t>());
        _Keys.push_back(make_unique<middle_white_key_t>(_MiddleWhitePathGeometry));
        _Keys.push_back(make_unique<black_key_t>());
        _Keys.push_back(make_unique<right_white_key_t>(_RightWhitePathGeometry));

        _Keys.push_back(make_unique<left_white_key_t>(_LeftWhitePathGeometry));
        _Keys.push_back(make_unique<black_key_t>());
        _Keys.push_back(make_unique<middle_white_key_t>(_MiddleWhitePathGeometry));
        _Keys.push_back(make_unique<black_key_t>());
        _Keys.push_back(make_unique<middle_white_key_t>(_MiddleWhitePathGeometry));
        _Keys.push_back(make_unique<black_key_t>());
        _Keys.push_back(make_unique<right_white_key_t>(_RightWhitePathGeometry));
    }

    _Keys.push_back(make_unique<white_key_t>());

    _Width = MeasureWidth();

    return hr;
}

/// <summary>
/// Creates the device-dependent resources.
/// </summary>
HRESULT keyboard_t::CreateDeviceDependentResources(ID2D1HwndRenderTarget * renderTarget) noexcept
{
    HRESULT hr = renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &_BlackBrush);

    if (SUCCEEDED(hr))
        hr = renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &_WhiteBrush);

    if (SUCCEEDED(hr))
        hr = renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::DodgerBlue), &_PushedBrush);

    return hr;
}

/// <summary>
/// Disposes the device-dependent resources.
/// </summary>
void keyboard_t::Dispose() noexcept
{
}
