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
            int c = 0;
            int[] d = new int[26];
            for (int i = 0; i < a; i++)
            {
                string b = Console.ReadLine();
                d = new int[26];
                for (int j = 0; j < b.Length; j++)
                {
                    char e = b[j];
                    d[b[j] - 97] += 1;
                    if ( j-1 >= 0)
                    {
                        if (e != b[j - 1] && d[b[j] - 97] >= 2)
                        {
                            c--;
                            break;
                        }
                    }
                }
                c++;
            }
            Console.WriteLine(c);
        }
    }
}