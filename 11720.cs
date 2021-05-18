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
            int a = Convert.ToInt32(Console.ReadLine());
            string b = Console.ReadLine();
            int sum = 0;
            for (int i = 0; i < a; i++)
            {
                sum = sum + Convert.ToInt32(b.Substring(i, 1));
            }
            Console.WriteLine(sum);
        }
    }
    
}
