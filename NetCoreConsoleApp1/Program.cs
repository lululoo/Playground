using System;
using System.Collections.Generic;
using System.Threading;

namespace NetCoreConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = new Test();
            t.Go();
        }


    }

    class Test
    {
        public void Go()
        {
            foreach(var i in GenerateInts())
            {
                Console.WriteLine($"i: {i}");

                foreach (var j in GenerateMoreInts(i))
                {
                    Console.WriteLine($"j: {j}");
                    var h = j;
                    var z = j;
                }
            }
        }

        public IEnumerable<int> GenerateInts()
        {
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine($"\tyield 1");
                yield return i;

                var j = i * 2;
                Console.WriteLine($"\tyield 2");
                yield return j;
            }
        }

        public IEnumerable<int> GenerateMoreInts(int max)
        {
            for (int i = 0; i < max; i++)
            {
                Console.WriteLine($"\t\t{i} yield1");
                yield return i;

                Console.WriteLine($"\t\t{i} yield2");
                yield return i + 1;
            }
        }
    }
}
