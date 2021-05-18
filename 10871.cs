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
            a = Console.ReadLine().Split(' ');
            string[] b;
            b = Console.ReadLine().Split(' ');
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < int.Parse(a[0]); i++)
            { 
                if(int.Parse(b[i]) < int.Parse(a[1]))
                {
                    stringBuilder.Append(int.Parse(b[i])+" ");
                }
            }
            Console.WriteLine(stringBuilder);

        }
    }
}
