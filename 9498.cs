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
            
            string c;
            if (Convert.ToInt32(a) >= 90 && Convert.ToInt32(a) <= 100)
            {
                c = "A";
            }
            else if (Convert.ToInt32(a) >= 80 && Convert.ToInt32(a) <= 89)
            {
                c = "B";
            }
            else if (Convert.ToInt32(a) >= 70 && Convert.ToInt32(a) <= 79)
            {
                c = "C";
            }
            else if (Convert.ToInt32(a) >= 60 && Convert.ToInt32(a) <= 69)
            {
                c = "D";
            }
            else
            {
                c = "F";
            }
            Console.WriteLine(c);
        }
    }
}
