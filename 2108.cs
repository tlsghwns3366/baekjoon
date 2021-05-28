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
            StringBuilder sb = new StringBuilder();
            int a = int.Parse(Console.ReadLine());
            int[] b = new int[a];
            double c = 0;
            int[] d = new int[8001];
            int e = 0;
            for (int i = 0; i < a; i++)
            {
                b[i] = int.Parse(Console.ReadLine());
                c += b[i];
                if (b[i] < 0)
                    d[4000-Math.Abs(b[i])]++;
                else
                    d[b[i] + 4000]++;
            }
            c = Math.Round(c / a);
            sb.AppendLine(c.ToString());
            Array.Sort(b);
            sb.AppendLine(b[a / 2].ToString());
            int f = 0;
            for (int i =0;i<8001;i++)
            {
                if (d.Max() == d[i])
                {
                    f++;
                    if (i < 4000)
                        e = -4000 + i;
                    else
                        e = i - 4000;
                }
                if (f == 2)
                    break;
            }
            sb.AppendLine(e.ToString());
            sb.AppendLine((b.Max() -b.Min()).ToString());
            Console.Write(sb);

        }
    }
}