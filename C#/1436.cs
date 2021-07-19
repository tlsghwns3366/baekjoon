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
            int b = 666;
            int c = 1;
            for(int i =0; i<3000000 ;i++)
            {
                if (a == 1)
                {
                    Console.WriteLine(b);
                    break;
                }
                else
                    b++;
                string d = b.ToString();
                for(int j =0;j<d.Length-2;j++)
                {
                    if (d[j] == '6' && d[j + 1] == '6' && d[j + 2] == '6')
                    {
                        c++;
                        break;
                    }
                }
                if(c==a)
                {
                    Console.WriteLine(b);
                    break;
                }
            }
        }
    }
}