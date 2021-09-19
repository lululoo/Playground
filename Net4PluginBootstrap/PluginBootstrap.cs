using Autofac;
using Net4Library;
using Net4Plugin;
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading;

namespace Net4PluginBootstrap
{
    public class PluginBootstrap : MarshalByRefObject, IPluginBootstrap
    {
        public void Load()
        {
            Console.WriteLine("Sleeping for 5s");
            Thread.Sleep(5000);

            var builder = new ContainerBuilder();


            try
            {
                string path = @"Net4Library.dll";
                byte[] buffer = File.ReadAllBytes(path);


                Assembly assm = Assembly.Load(buffer);

                Type[] types = assm.GetTypes();
                foreach (Type type in types.Where(t => t.Name.EndsWith("Plugin")))
                {
                    Console.WriteLine($"Loading plugin {type.FullName}");

                    var plugin = AppDomain.CurrentDomain.CreateInstance(type.Assembly.FullName, type.FullName);
                    var api = plugin.Unwrap() as Plugin;

                    Console.WriteLine("Registering modules");
                    var modules = api.GetModules();
                    foreach (var m in modules)
                    {
                        builder.RegisterModule(m);                        
                    }

                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("Building container");

            var scope = builder.Build();

            Console.WriteLine("Resolving IUtility\n");

            var utility = scope.Resolve<IUtility>();
            utility.HelpWithThat();
            utility.HelpWithThis();

            Console.WriteLine("");
        }
    }
}
