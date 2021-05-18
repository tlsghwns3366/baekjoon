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
            StringBuilder st = new StringBuilder();
            for (; ; )
            {
                string[] a = Console.ReadLine().Split(' ');
                if (int.Parse(a[0]) == 0 && int.Parse(a[1]) == 0 && int.Parse(a[2]) == 0)
                    break;
                int[] b = new int[] { int.Parse(a[0]), int.Parse(a[1]), int.Parse(a[2]) };
                b[0] = b[0] * b[0];
                b[1] = b[1] * b[1];
                b[2] = b[2] * b[2];
                if (b[0] == b[1] + b[2])
                    st.AppendLine("right");
                else if (b[1] == b[0] + b[2])
                    st.AppendLine("right");
                else if (b[2] == b[0] + b[1])
                    st.AppendLine("right");
                else
                    st.AppendLine("wrong");
            }
            Console.Write(st);
        }
    }
}