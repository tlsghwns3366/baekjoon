using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string 입력;
            입력 = Console.ReadLine();
            for(int i=0;i<Convert.ToInt32(입력);i++)
            {
                for(int j = Convert.ToInt32(입력)-1; j>i;j--)
                Console.Write(" ");
                for (int j = 0; j <= i; j++)
                    Console.Write("*");
                Console.WriteLine();
            }
        }
    }
}
