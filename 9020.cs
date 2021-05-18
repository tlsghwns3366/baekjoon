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
            for (int i = 0; i < a; i++)
            {
                int b = int.Parse(Console.ReadLine());

                int[] t = new int[b + 1];
                Array.Clear(t, 0, b + 1);
                int c = (int)Math.Sqrt(b);
                t[1] = 1;
                for (int j = 2; j <= c; j++) // 소수 찾기
                {
                    for (int k = j + j; k < b + 1; k = k + j)
                    {
                        t[k] = 1;
                    }
                }
                int d = 0;
                int e = 0;
                for (int j = b / 2; j < b; j++)
                {
                    if (t[j] != 1)
                    {
                        e = j;
                        d = b - e;
                        if (t[d] == 0)
                            break;
                    }
                }
                st.AppendLine(d.ToString());
                st.AppendLine(e.ToString());
            }
            Console.Write(st.ToString());
        }
    }
}