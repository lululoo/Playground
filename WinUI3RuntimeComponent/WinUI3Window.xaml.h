#pragma once

#include "WinUI3Window.g.h"

namespace winrt::WinUI3RuntimeComponent::implementation
{
    struct WinUI3Window : WinUI3WindowT<WinUI3Window>
    {
        WinUI3Window();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::WinUI3RuntimeComponent::factory_implementation
{
    struct WinUI3Window : WinUI3WindowT<WinUI3Window, implementation::WinUI3Window>
    {
    };
}
