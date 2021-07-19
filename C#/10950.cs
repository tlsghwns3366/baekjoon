using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            string a;
            a = Console.ReadLine();
            string[] b = new string[Convert.ToInt32(a)*2];
            for (int i = 0; i < Convert.ToInt32(a)*2; i = i+2)
            {
                string c;
                string[] d;
                c = Console.ReadLine();
                d = c.Split(' ');
                b[i] = d[0];
                b[i+1] = d[1];
            }
            for(int i = 0;i<b.Length-1;i = i+2)
            {
                Console.WriteLine(Convert.ToInt32(b[i]) + Convert.ToInt32(b[i+1]));
            }
        }
    }
}
