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
            string a = Console.ReadLine();
            for (int i = 97; i < 123; i++)
            {
                char c = Convert.ToChar(i);
                if(a.IndexOf(c) != -1)
                {
                    Console.Write(a.IndexOf(c));
                }
                else
                {
                    Console.Write("-1");
                }
                Console.Write(" ");
            }
            
        }
    }
    
}
