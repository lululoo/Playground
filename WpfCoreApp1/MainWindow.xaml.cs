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
            //var uwp = new UWPLibrary.UWPDialog(); //runtime error The application called an interface that was marshalled for a different thread.
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
            var sleepTask = SleepAsync(5000);

            // This blocks the UI thread.
            // SleepAsync attempts to resume execution of its code below the first await on the UI thread after it sleeps.
            //      this is to support chaining async methods that access the UI!
            //      "by default, the current context is captured at the time an asynchronous method is suspended, and that captured context is used to invoke the asynchronous method's continuation upon resumption"
            // = DEADLOCK!
            // bc SleepAsync will be able to resume execution
            sleepTask.Wait();

            Debug.WriteLine("Done with button click");

            myInkCanvas.Height = 50;
        }

        private void ExceptionTest_Click(object sender, RoutedEventArgs e)
        {
            var exceptionTask = ThrowExceptionAsync();
            //exceptionTask.GetAwaiter().GetResult(); //deadlock!
            Task.Run(() => {
                try
                {
                    exceptionTask.GetAwaiter().GetResult();
                    // throws original exception
                }
                catch (AggregateException)
                {
                    Debug.WriteLine("GetResult: aggregate");
                }
                catch (Exception e)
                {
                    Debug.WriteLine("GetResult: exception " + e.Message);
                }

                try
                {
                    ThrowExceptionAsync().Wait();
                    // throws AggregateException
                }
                catch (AggregateException)
                {
                    Debug.WriteLine("Wait: aggregate");
                }
                catch (Exception e)
                {
                    Debug.WriteLine("Wait: exception " + e.Message);
                }
            });

            Task.Run(async () =>
            {
                try
                {
                    await ThrowExceptionAsync();
                    // throws original exception
                }
                catch (AggregateException)
                {
                    Debug.WriteLine("await: aggregate");
                }
                catch (Exception e)
                {
                    Debug.WriteLine("await: exception " + e.Message);
                }
            });
        }

        private void Button_Click_NoDeadlock(object sender, RoutedEventArgs e)
        {
            Task.Run(() =>
            {
                
                SleepAsync(5000)
                    //.Wait();  // This blocks the UI thread
                    .GetAwaiter().GetResult();

                Debug.WriteLine("Done with button click");

                // but now this is required since we aren't on the UI thread
                Dispatcher.Invoke(() =>
                {
                    myInkCanvas.Height = 50;
                });
            });
        }

        private async Task SleepAsync(int ms)
        {
            await Task.Delay(ms); //.ConfigureAwait(false); - this will prevent the next line from running in the UI context

            Debug.WriteLine("I'm awake");
        }

        private async Task ThrowExceptionAsync()
        {
            await SleepAsync(1000);

            throw new Exception("testing");
        }


    }
}
