using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Net4Library
{
    public class Utility : IUtility
    {
        public void HelpWithThis()
        {
            Console.WriteLine("Helping this!");
        }

        public void HelpWithThat()
        {
            Console.WriteLine("Helping that!");
        }
    }
}
