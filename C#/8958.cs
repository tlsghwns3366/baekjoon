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
            int a = int.Parse(Console.ReadLine());
            StringBuilder stringBuilder = new StringBuilder();
            for(int i =0;i < a;i++)
            {
                string b = Console.ReadLine();
                char[] c = b.ToCharArray();
                int count = 0;
                int sum = 0;
                for(int j = 0; j < c.Length; j++)
                {
                    if(c[j] == 'O')
                    {
                        count++;
                        sum = sum + count;
                    }
                    else
                    {
                        count = 0;
                    }
                }
                stringBuilder.AppendLine(sum+"");
            }
            Console.Write(stringBuilder.ToString());
        }
    }
}
