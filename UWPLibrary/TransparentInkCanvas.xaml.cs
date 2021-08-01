using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Core;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

namespace UWPLibrary
{
    public sealed partial class TransparentInkCanvas : UserControl
    {
        public TransparentInkCanvas()
        {
            this.InitializeComponent();

            this.myCanvas.InkPresenter.InputDeviceTypes = CoreInputDeviceTypes.Mouse | CoreInputDeviceTypes.Pen;
            myCanvas.InkPresenter.IsInputEnabled = true;
            myToolbar.TargetInkCanvas = myCanvas;

        }

        private void myCanvas_GotFocus(object sender, RoutedEventArgs e)
        {
            var i = 0;
        }
    }
}
