using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02_Even_Fibonacci
{
    internal class Program
    {
        static void Main(string[] args)
        {
            long sum = 0;
            long fib1 = 0;
            long fib2 = 1;
            while (fib1 < 4000000)
            {
                long fib = fib1 + fib2;

                if (fib % 2 == 0)
                {
                    sum += fib;
                }

                Console.WriteLine("{0} {1} {2} {3}", fib1, fib2, fib, sum);

                fib1 = fib2;
                fib2 = fib;
            }

            Console.WriteLine("The sum is {0}", sum);
        }

    }

}
