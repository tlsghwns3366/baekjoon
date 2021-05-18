using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main()
        {
            string n;
            int len = 1;
            n = Console.ReadLine();
            if (n[0] == ' ')
            {
                len--;
            }
             if (n[n.Length-1] == ' ')
             {
                 len--;
             }
            for (int i = 0; i < n.Length; i++)
            {
                
                if (n[i] == ' ')
                {
                    len++;
                    continue;
                }
            }
            Console.WriteLine(len);
        }
    }
}
