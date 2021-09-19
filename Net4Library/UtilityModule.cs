using Autofac;

namespace Net4Library
{
    public class UtilityModule : Module
    {

        public bool DoThisOrThat { get; set; }

        public UtilityModule()
        {
        }

        protected override void Load(ContainerBuilder builder)
        {
            builder.RegisterType<Utility>().As<IUtility>();
        }
    }
}
