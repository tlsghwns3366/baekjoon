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
            int[][] b = new int[a][];
            for (int i = 0; i < a; i++)
            {
                string[] c = Console.ReadLine().Split(' ');
                b[i] = new int[] { int.Parse(c[0]), int.Parse(c[1]) };
            }
            var sort = b.OrderBy(x => x[1]).ThenBy(x => x[0]);
            foreach (int[] e in sort)
            {
                sb.AppendLine(e[0] + " " + e[1]);
            }
            Console.Write(sb);
        }
    }
}