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
            int a= int.Parse(Console.ReadLine());
            StringBuilder st = new StringBuilder();
            for (int i = 0; i < a; i++)
            {
                string[] b = Console.ReadLine().Split(' ');
                int n = int.Parse(b[1]);
                int r = int.Parse(b[0]);
                int s = 1;

                for (int j = 1; j <= r; j++)
                {
                    s = s * (n - j + 1) / j;
                }
                st.AppendLine(s.ToString());
            }
            Console.Write(st);
        }
    }
}