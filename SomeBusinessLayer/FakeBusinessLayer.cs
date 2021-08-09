using NETStandardLibrary;
using System;
using System.Diagnostics;
using System.Threading.Tasks;

namespace SomeBusinessLayer
{
    /// <summary>
    /// A fake business layer
    /// </summary>
    public class FakeBusinessLayer
    {
        ILegacyApplication _LegacyApplication;

        public FakeBusinessLayer(ILegacyApplication legacyApp)
        {
            _LegacyApplication = legacyApp;
        }

        public async Task DoStuffRequiringAuthAsync()
        {
            var token = _LegacyApplication.GetAuthToken();

            await MakeWebRequestAsync(token);

            Debug.WriteLine("testing... zzz");
        }

        private async Task MakeWebRequestAsync(string authToken)
        {
            Debug.WriteLine($"faking a web request using authToken: {authToken}");
            await Task.Delay(1000);
        }
    }
}
