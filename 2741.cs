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
            string a;
            a = Console.ReadLine();
            StringWriter stringWriter = new StringWriter();
            for (int i = 1; i <= Convert.ToInt32(a); i++)
            {
                stringWriter.WriteLine(i);
            }
            Console.Write(stringWriter.ToString());
        }
    }
}
