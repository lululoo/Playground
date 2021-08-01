#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "WinUI3Control.g.h"

namespace winrt::WinUI3RuntimeComponent::implementation
{
    struct WinUI3Control : WinUI3ControlT<WinUI3Control>
    {
        WinUI3Control();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::WinUI3RuntimeComponent::factory_implementation
{
    struct WinUI3Control : WinUI3ControlT<WinUI3Control, implementation::WinUI3Control>
    {
    };
}
