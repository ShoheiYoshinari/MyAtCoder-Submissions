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
            string s = Console.ReadLine();
            int cnt = 0;

            for(int i = 0; i < s.Length; i++)
            {
                if (s[i] == '1') cnt++;
            }
            Console.WriteLine(cnt);
            
        }
    }
}