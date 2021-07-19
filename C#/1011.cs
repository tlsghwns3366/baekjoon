using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            for(int i =0; i < a; i++)
            {
                string[] b = Console.ReadLine().Split(' ');
                long c1 = long.Parse(b[0]);
                long c2 = long.Parse(b[1]);
                long d = c2 - c1;
                long e = 0, k = 0;
                if(c1 == 0)
                {
                    e++;
                    k++;
                    d--;
                }
                while (d != 0)
                {
                    long s = 0;
                    s = (k + 2) * (k+1 )/ 2;
                    if (d - s + k+1 < 0 && k != 1)
                    {
                        k--;
                    }
                    else if (d - s >= 0)
                    {
                        k++;
                    }
                    e++;
                    d -= k;
                }
                Console.WriteLine(e);
            }
        }
    }
}