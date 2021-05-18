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
            string b;
            string[] a;
            StringBuilder stringBuilder = new StringBuilder();
            while (true)
            {
                b = Console.ReadLine();
                if (b == null)
                {
                    break;
                }
                a = b.Split(' ');
                stringBuilder.Append(int.Parse(a[0]) + int.Parse(a[1]) + "\n");
            }
            Console.Write(stringBuilder);
        }
    }
}
