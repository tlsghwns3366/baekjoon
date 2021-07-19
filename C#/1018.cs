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
            string[] a = Console.ReadLine().Split(' ');
            int a1 = int.Parse(a[0]);
            int a2 = int.Parse(a[1]);
            string[,] c = new string[a1, a2];
            int s = a1*a2;
            for (int i = 0; i < a1; i++)
            {
                string e = Console.ReadLine();
                for (int j = 0; j < a2; j++)
                {
                    c[i, j] = e[j].ToString();
                }
            }
            int e1 = 0;
            int e2 = 0;
            while (true)
            {
                int d = 0;
                for (int i = e1; i < e1+8; i++)
                {
                    for (int j = e2; j < e2+8; j++)
                    {
                            if (c[i, j] != "W" && (i+e1) % 2 == 0 && (j+e2) % 2 == 0)
                                d++;
                            else if (c[i, j] != "B" && (i + e1) % 2 == 0 && (j + e2) % 2 == 1)
                                d++;
                            else if (c[i, j] != "B" && (i + e1) % 2 == 1 && (j + e2) % 2 == 0)
                                d++;
                            else if (c[i, j] != "W" && (i + e1) % 2 == 1 && (j + e2) % 2 == 1)
                                d++;
                    }
                }
                if (s > d)
                    s = d;
                d = 0;
                for (int i = e1; i < e1 + 8; i++)
                {
                    for (int j = e2; j < e2 + 8; j++)
                    {
                        if (c[i, j] != "B" && (i + e1) % 2 == 0 && (j + e2) % 2 == 0)
                            d++;
                        else if (c[i, j] != "W" && (i + e1) % 2 == 0 && (j + e2) % 2 == 1)
                            d++;
                        else if (c[i, j] != "W" && (i + e1) % 2 == 1 && (j + e2) % 2 == 0)
                            d++;
                        else if (c[i, j] != "B" && (i + e1) % 2 == 1 && (j + e2) % 2 == 1)
                            d++;
                    }
                }
                if (s > d)
                    s = d;

                 if (e2 + 8 == a2)
                {
                    e1++;
                    e2 = 0;
                    if (e1 + 8 > a1)
                        break;
                }
                else
                    e2++;
            }
            Console.WriteLine(s);
        }
    }
}