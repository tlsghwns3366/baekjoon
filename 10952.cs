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
            string[] a;
            
            StringBuilder stringBuilder = new StringBuilder();
            while (true)
            {
                a = Console.ReadLine().Split(' ');
                if (a[0] == "0" && a[1] == "0")
                {
                    break;
                }
                stringBuilder.Append(int.Parse(a[0]) + int.Parse(a[1])+"\n");
            }
            Console.Write(stringBuilder);
        }
    }
}
