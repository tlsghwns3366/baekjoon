using System;
using System.Text;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(Console.OpenStandardInput());
            StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

            int a = int.Parse(sr.ReadLine());
            int[] c = new int[10001];
            for (int i = 0; i < a; i++)
            {
                c[int.Parse(sr.ReadLine())]++;
            }
            int x = 0;
            for(int i =0;i<10001;i++)
            {
                if (c[i] != 0)
                {
                    for (int j = 0; j < c[i]; j++)
                    {
                        sw.WriteLine(i);
                    }
                }
            }
            sr.Close();
            sw.Close();
        }
    }
}