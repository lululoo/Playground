using Net4Plugin;
using System;
using System.IO;
using System.Linq;
using System.Reflection;

namespace Net4ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {            
            Load();
        }


        private static void Load()
        {
            AppDomain appDomain = null;
            try
            {
                string path = @"Net4PluginBootstrap.dll";
                byte[] buffer = File.ReadAllBytes(path);

                appDomain = AppDomain.CreateDomain("Test", null, new AppDomainSetup
                {
                    ShadowCopyFiles = "true",
                });

                Assembly assm = appDomain.Load(buffer);

                Type[] types = assm.GetTypes();
                Type type = types.FirstOrDefault(t => t.Name.EndsWith("PluginBootstrap"));

                var bootstrap = appDomain.CreateInstance(type.Assembly.FullName, type.FullName)
                    .Unwrap() as IPluginBootstrap;

                Console.WriteLine("Loading bootstrap");

                bootstrap.Load();
                
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                if (appDomain != null)
                {
                    AppDomain.Unload(appDomain);
                    Console.WriteLine("Unloaded appdomain");
                }
                    
            }
        }
    }
}
