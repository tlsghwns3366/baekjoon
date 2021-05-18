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
            string[] b;
            a = Console.ReadLine();
            b = a.Split(' ');
            string c;
            if (Convert.ToInt32(b[0]) > Convert.ToInt32(b[1]))
            {
                c = ">";
            }
            else if (Convert.ToInt32(b[0]) < Convert.ToInt32(b[1]))
            {
                c = "<";
            }
            else
            {
                c = "==";
            }
            Console.WriteLine(c);
        }
    }
}
