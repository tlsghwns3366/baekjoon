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
            string a= Console.ReadLine();
            int b = 0;
            for(int i = 0; i < a.Length; i++)
            {
                switch (a[i])
                {
                    case 'A':
                    case 'B':
                    case 'C':
                        b = b + 3;
                        break;
                    case 'D':
                    case 'E':
                    case 'F':
                        b = b + 4;
                        break;
                    case 'G':
                    case 'H':
                    case 'I':
                        b = b + 5;
                        break;
                    case 'J':
                    case 'K':
                    case 'L':
                        b = b + 6;
                        break;
                    case 'M':
                    case 'N':
                    case 'O':
                        b = b + 7;
                        break;
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                        b = b + 8;
                        break;
                    case 'T':
                    case 'U':
                    case 'V':
                        b = b + 9;
                        break;
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                        b = b + 10;
                        break;
                }
            }
            Console.WriteLine(b);
        }
    }
    
}
