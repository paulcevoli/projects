using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_Multiples
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var sum = 0;

            for (int i = 0; i < 1000; i++)
            {
                if ( (i % 3 == 0) || (i % 5 == 0))
                {
                    sum += i;
                }
            }

            Console.WriteLine("The sum of multiples of 3 and 5 for numbers less than 1000 is {0}", sum);
            Console.Read();
        }
    }
}
