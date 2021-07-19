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
            string a= Console.ReadLine();
            int b = 0;
            for (int i = 0; i < a.Length; i++)
            {
                if (i + 1 != a.Length && (a[i] == 'c' || a[i] == 's' || a[i] == 'z'))
                {
                    if (a[i + 1] == '=' || a[i + 1] == '-')
                    {
                        i++;
                    }
                }
                else if (i + 1 != a.Length &&  a[i] == 'd')
                {
                    if (a[i + 1] == '-')
                    {
                        i++;
                    }
                    else if (i + 2 != a.Length)
                    {
                        if (a[i + 1] == 'z' && a[i + 2] == '=')
                        {
                            i++;
                            i++;
                        }
                    }
                }
                else if (i + 1 != a.Length &&( a[i] == 'l' || a[i] == 'n'))
                {
                    if (a[i + 1] == 'j')
                    {
                        i++;
                    }
                }
                b++;
            }
            Console.WriteLine(b);
        }
    }
}