using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string 입력;
            입력 = Console.ReadLine();
            int 숫자, 합1 = 0, 합2 = 0, 합3 = 0;
            숫자 = Convert.ToInt32(입력);
            
            for (int i = 1;i <= 숫자;i++)
            {
                if (i == 1)
                {
                    합2 = 1;
                }
                if (i == 2)
                {
                    합3 = 1;
                }
                else
                {
                    합3 = 합1 + 합2;
                    합1 = 합2;
                    합2 = 합3;
                }
            }
            Console.WriteLine(합3);
        }
    }
}
