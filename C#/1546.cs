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
            string[] b = Console.ReadLine().Split(' ');
            double max = int.Parse(b[0]);
            for(int i = 0; i < a; i++)
            {
                if(int.Parse(b[i]) > max)
                {
                    max = int.Parse(b[i]);
                }
            }
            double avg=0;
            for(int i = 0; i < a; i++)
            {
                avg += (int.Parse(b[i]) / max)*100;
            }
            Console.WriteLine(avg / a);
        }
    }
}
