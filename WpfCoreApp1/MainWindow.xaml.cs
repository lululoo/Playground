using Microsoft.Toolkit.Win32.UI.Controls.Interop.WinRT;
using Microsoft.Toolkit.Wpf.UI.XamlHost;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfCoreApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //var winui3 = new MyWinUI3Window(); //runtime error - com exception
            var uwp = new UWPLibrary.UWPDialog(); //runtime error The application called an interface that was marshalled for a different thread.
                                                  // fixed by creating a msix package around the wpf app            
                                                  //uwp.ShowAsync(); // runtime error about it being on some other root

            this.myInkCanvas.InkPresenter.InputDeviceTypes = CoreInputDeviceTypes.Mouse | CoreInputDeviceTypes.Pen;

            
        }

        private void MyCalendar_ChildChanged(object sender, EventArgs e)
        {
            WindowsXamlHost windowsXamlHost = (WindowsXamlHost)sender;

            Windows.UI.Xaml.Controls.CalendarView calendarView =
                (Windows.UI.Xaml.Controls.CalendarView)windowsXamlHost.Child;

            if (calendarView != null)
            {
                calendarView.SelectedDatesChanged += (obj, args) =>
                {
                    if (args.AddedDates.Count > 0)
                    {
                        MessageBox.Show("The user selected a new date: " +
                            args.AddedDates[0].DateTime.ToString());
                    }
                };
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            SleepAsync(5000).Wait();

            Debug.WriteLine("Done with button click");

            myInkCanvas.Height = 50;
        }

        private async Task SleepAsync(int ms)
        {
            await Task.Delay(ms); //.ConfigureAwait(false); - this will prevent the next line from running in the same context
            
            Debug.WriteLine("I'm awake");
        }
    }
}
