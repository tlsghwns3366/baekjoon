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
            StringBuilder stringBuilder = new StringBuilder();
            for(int i =0;i < a;i++)
            {
                string[] b = Console.ReadLine().Split(' ');
                double avg = 0.0;
                double c = 0;
                for(int j = 1; j < b.Length; j++)
                {
                    avg += double.Parse(b[j]);
                }
                avg = avg / double.Parse(b[0]);
                for (int j = 1; j < b.Length; j++)
                {
                    if(double.Parse(b[j])>avg)
                    {
                        c++;
                    }
                }
                
                stringBuilder.AppendFormat("{0:#0.000}%\n",(c / double.Parse(b[0]))*100);
            }
            Console.Write(stringBuilder.ToString());
        }
    }
}
