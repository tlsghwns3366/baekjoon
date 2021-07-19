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
            int a = int.Parse(Console.ReadLine());
            int c = 0;
            StringBuilder stringBuilder = new StringBuilder();
            for ( int i =0;i < a; i++)
            {
                string[] b = Console.ReadLine().Split(' ');
                int h, w, n;
                h = int.Parse(b[0]);
                w = int.Parse(b[1]);
                n = int.Parse(b[2]);

                if (n % h == 0)
                    c = h * 100;
                else
                    c = (n % h) * 100;
                if(n%h != 0)
                    c = c + (n / h+1);
                else
                    c = c + (n / h);
                stringBuilder.AppendLine(c.ToString());
            }
            Console.Write(stringBuilder.ToString());
        }
    }
}