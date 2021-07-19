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
            string a = "v";
            a = Console.ReadLine();
            string line;
            StringReader reader;
            StringWriter stringWriter = new StringWriter();
            for (int i = 0; i < Convert.ToInt32(a); i++)
            {
                string[] b;
                b = Console.ReadLine().Split(' ');
                int c = Convert.ToInt32(b[0]) + Convert.ToInt32(b[1]);
                reader = new StringReader(c.ToString());
                stringWriter.WriteLine(reader.ReadLine());
            }
            Console.Write(stringWriter.ToString());

        }
    }
}
