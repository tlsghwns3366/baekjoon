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
            int a = int.Parse(Console.ReadLine());
            StringBuilder st = new StringBuilder();
            for(int i =0;i <a; i++)
            {
                string[] b = Console.ReadLine().Split(' ');
                if (b[0] == b[3] && b[1] == b[4] && b[2] == b[5])
                {
                    st.AppendLine((-1).ToString());
                    continue;
                }
                int[] c = new int[] { int.Parse(b[0]), int.Parse(b[1]), int.Parse(b[2]), int.Parse(b[3]), int.Parse(b[4]), int.Parse(b[5]) };
                double d = Math.Sqrt((c[0] - c[3]) * (c[0] - c[3])+(c[1] - c[4]) * (c[1] - c[4]));
                if (c[2] + c[5] == d || Math.Abs(c[2] - c[5]) == d)
                {
                    st.AppendLine(1.ToString());
                }
                else if (c[2] + c[5] > d && Math.Abs(c[2] - c[5]) < d)
                {
                    st.AppendLine(2.ToString());
                }
                else
                    st.AppendLine(0.ToString());
            }
            Console.Write(st);
        }
    }
}