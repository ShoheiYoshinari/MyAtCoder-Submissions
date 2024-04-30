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
            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            var a = Enumerable.Repeat(0, n).ToArray();
            
            for(int i = 0; i < n; i++)
            {
                a[i] = int.Parse(input[i]);
            }

            int cnt = 0;
            int wari = 2;
            while (true)
            {
                bool odd = false;
                for(int i = 0; i < n; i++)
                {
                    if (a[i] % wari != 0) odd = true;
                }
                if (!odd)
                {
                    cnt++;
                    wari *= 2;
                }
                else
                {
                    break;
                }
            }
            Console.WriteLine($"{cnt}");

        }
    }
}