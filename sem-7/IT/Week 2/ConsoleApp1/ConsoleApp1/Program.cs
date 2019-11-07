using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int num1, num2;
            Console.WriteLine("Enter two numbers");
            string numString1 = Console.ReadLine();
            string numString2 = Console.ReadLine();

            int.TryParse(numString1, out num1);
            int.TryParse(numString2, out num2);

            int res = num1 + num2;

            Console.WriteLine("The result of addition of {0} and {1} is {2}", num1, num2, res);
            // Console.Read();
        }
    }
}
