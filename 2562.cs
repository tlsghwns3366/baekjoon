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
            int[] a = new int[9];
            for (int i = 0; i < 9; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }
            int max = a[0] ;
            int b=0;
            for(int i =0; i < 9 ;i++)
            {
                if (a[i] > max)
                {
                    max = a[i];
                    b = i;
                }
            }
            Console.WriteLine(a[b]);
            Console.WriteLine(b+1);
        }
    }
}