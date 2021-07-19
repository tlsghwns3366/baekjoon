using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string a;
            string[] b;
            a = Console.ReadLine();
            b = a.Split(' ');
            double c;
            c = Convert.ToDouble(b[0]) / Convert.ToDouble(b[1]);
            Console.Write(c);
        }
    }
}
