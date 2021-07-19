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
            string a;
            a = Console.ReadLine();
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 1; i <= Convert.ToInt32(a); i++)
            {
                string[] b = Console.ReadLine().Split(' ');
                stringBuilder.AppendFormat("Case #{0}: {1} + {2} = {3}\n",i, int.Parse(b[0]), int.Parse(b[1]),( int.Parse(b[0]) + int.Parse(b[1])));
            }
            Console.WriteLine(stringBuilder);
        }
    }
}
