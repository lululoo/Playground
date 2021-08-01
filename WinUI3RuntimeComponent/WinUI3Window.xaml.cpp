#include "pch.h"
#include "WinUI3Window.xaml.h"
#if __has_include("WinUI3Window.g.cpp")
#include "WinUI3Window.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3RuntimeComponent::implementation
{
    WinUI3Window::WinUI3Window()
    {
        InitializeComponent();
    }

    int32_t WinUI3Window::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void WinUI3Window::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void WinUI3Window::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
