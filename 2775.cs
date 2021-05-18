using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            for(int i = 0; i < a; i++)
            {
                int b = int.Parse(Console.ReadLine());
                int c = int.Parse(Console.ReadLine());
                int[,] d = new int[b+1,c];
                d[0, 0] = 1;
                for (int j = 1; j < c; j++)
                {
                    d[0, j] = d[0, j-1]+1;
                }
                for(int j =1;j<b+1;j++)
                {
                    for (int m = 0; m < c; m++)
                    {
                        for (int k = 0; k <= m; k++)
                        {
                            if (m == 0)
                            {
                                d[j, m] = 1;
                            }
                            else
                            {
                                d[j, m] += d[j - 1, k];
                            }
                        }
                    }
                }
                Console.WriteLine(d[b, c-1]);
            }
        }
    }
}