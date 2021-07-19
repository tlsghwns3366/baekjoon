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
            string[] 분할;
            string[] s;
            int[] q;
            a = Console.ReadLine();
            s = new string[Convert.ToInt32(a)];
            q = new int[Convert.ToInt32(a)];
            for (int w = 0; w < Convert.ToInt32(a); w++)
            { //입력
                분할 = Console.ReadLine().Split(' ');
                q[w] = Convert.ToInt32(분할[0]);
                s[w] = 분할[1];
            }
            for (int w = 0; w < Convert.ToInt32(a); w++)
            {
                string s2;
                s2 = s[w];
                for (int k = 0; k < s2.Length; k++)
                {
                    for (int j = 0; j < q[w]; j++) //문자 반복
                    {
                        Console.Write(s2[k]);
                    }
                }
                Console.Write("\n");
            }
        }
    }
}
