using Autofac;
using System.Collections.Generic;

namespace Net4Plugin
{
    public abstract class Plugin
    {
        public abstract IEnumerable<Module> GetModules();        
    }
}
