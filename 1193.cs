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
            int b = 1;
            int c = 1;
            bool d = true;
            int e=1;
            while (e<a)
            {
                if (b == 1 && d)
                {
                    c = c + 1;
                    d = false;
                    e++;
                    continue;
                }
                else if (c == 1 && !d)
                {
                    b = b + 1;
                    d = true;
                    e++;
                    continue;
                }
                if(!d)
                {
                    if (c - 1 != 0)
                    {
                        b = b + 1;
                        c = c - 1;
                    }
                    else
                        continue;
                }
                else
                {
                    if (b - 1 != 0)
                    {
                        b = b - 1;
                        c = c + 1;
                    }
                    else
                        continue;
                }
                e++;
            }
            Console.WriteLine(b + "/" + c);
        }

    }
}