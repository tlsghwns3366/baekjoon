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
        static StringBuilder st = new StringBuilder();
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b1 = 1;
            int b2 = 2;
            int b3 = 3;

            st.AppendLine(((2<<a-1)-1).ToString());
            Ha(a, b1, b2, b3);
            Console.Write(st);
        }
        static void Ha(int a,int b1, int b2, int b3)
        {
            if (a == 1)
            {
                st.AppendLine(b1 + " " + b3);
            }
            else
            {
                Ha(a - 1, b1, b3, b2);
                st.AppendLine(b1 + " " + b3);
                Ha(a - 1, b2, b1, b3);
            }
        }
    }
}