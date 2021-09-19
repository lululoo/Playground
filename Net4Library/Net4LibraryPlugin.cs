using Autofac;
using Net4Plugin;
using System.Collections.Generic;

namespace Net4Library
{
    public class Net4LibraryPlugin : Plugin
    {
        public override IEnumerable<Module> GetModules()
        {
            return new List<Module> {
                new UtilityModule(),
            };
        }
    }
}
