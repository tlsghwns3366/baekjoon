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
            int[] b = new int[a];
            for(int i =0; i<a;i++)
            {
                b[i] = int.Parse(Console.ReadLine());
            }
            for(int i =0; i<a;i++)
            {
                for(int j = i;j<a;j++)
                {
                    if(b[i] > b[j])
                    {
                        int c = b[i];
                        b[i] = b[j];
                        b[j] = c;
                    }
                }
            }
            for (int i = 0; i < a; i++)
            {
                Console.WriteLine(b[i]);
            }
        }
    }
}