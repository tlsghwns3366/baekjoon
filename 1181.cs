using System;
using System.Text;
using System.Linq;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            StringBuilder sb = new StringBuilder();
            string[] b = new string[a];
            for (int i = 0; i < a; i++)
            {
                b[i] = Console.ReadLine();
            }
            
            var sort = b.OrderBy(x => x.Length).ThenBy(x=>x).Distinct();
            foreach (string e in sort)
            {
                sb.AppendLine(e);
            }
            Console.Write(sb);
        }
    }
}