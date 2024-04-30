using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem3_6
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] array = Console.ReadLine().Split().Select(long.Parse).ToArray();

            long n = array[0];
            long y = array[1] / 1000;

            long a = -1;
            long b = -1;
            long c = -1;
            bool ok = false;

            for(long i = n; i >= 0; i--)
            {
                for(long j = n - i; j >= 0; j--)
                {
                    long k = n - i - j;
                    if((i*10) + (j*5) + k == y)
                    {
                        a = i;
                        b = j;
                        c = k;
                        ok = true;
                    }
                    if (ok) break;
                }
            }
            Console.WriteLine($"{a} {b} {c}");


            



        }
    }
}