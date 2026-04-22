
/** $VER: Keyboard.h (2023.01.15) P. Stuer **/

#pragma once

using namespace std;

#include <CppCoreCheck\Warnings.h>
#pragma warning(disable: 5045 5262 ALL_CPPCORECHECK_WARNINGS)

#include <atlcomcli.h> // CComPtr

#include "Key.h"

#pragma warning(disable: 4820)
class keyboard_t
{
public:
    keyboard_t();
    ~keyboard_t();

    float GetWidth() const noexcept
    {
        return _Width;
    }

    float GetHeight() const noexcept
    {
        return _Keys[0]->GetHeight() * _ScaleMatrix.m22;
    }

    void SetScale(float scale) noexcept
    {
        _ScaleMatrix = D2D1::Matrix3x2F::Scale(D2D1::Size(scale, scale));
    }

    size_t GetKeyCount() const
    {
        return _Keys.size();
    }

    void PushKey(size_t index) const
    {
        if (index < 21)
            return;

        index -= 21;
 
        if (index < _Keys.size())
            _Keys[index]->Push();
    }

    void ReleaseKey(size_t index) const
    {
        if (index < 21)
            return;

        index -= 21;

        if (index < _Keys.size())
            _Keys[index]->Release();
    }

    void Reset() const
    {
        for (auto & Iterator : _Keys)
            Iterator->Release();
    }

    #pragma region("Direct2D")
    HRESULT CreateDeviceIndependentResources(ID2D1Factory * d2DFactory) noexcept;
    HRESULT CreateDeviceDependentResources(ID2D1HwndRenderTarget * renderTarget) noexcept;
    void Dispose() noexcept;

    HRESULT Render(ID2D1HwndRenderTarget * renderTarget, float x, float y) const noexcept;
    #pragma endregion

private:
    float MeasureWidth() const noexcept;

private:
    vector<unique_ptr<key_t>> _Keys;
    float _Width;

    #pragma region("Direct2D")
    // Device-independent resources
    CComPtr<ID2D1PathGeometry> _LeftWhitePathGeometry;
    CComPtr<ID2D1PathGeometry> _MiddleWhitePathGeometry;
    CComPtr<ID2D1PathGeometry> _RightWhitePathGeometry;

    // Device-dependent resources
    CComPtr<ID2D1SolidColorBrush> _BlackBrush;
    CComPtr<ID2D1SolidColorBrush> _WhiteBrush;
    CComPtr<ID2D1SolidColorBrush> _PushedBrush;

    D2D1::Matrix3x2F _ScaleMatrix;
    #pragma endregion
};
#pragma warning(default: 4820)
