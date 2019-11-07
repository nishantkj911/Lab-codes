using System;

namespace Question1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter two numbers");
            int num1, num2;
            int.TryParse(Console.ReadLine(), out num1);
            int.TryParse(Console.ReadLine(), out num2);

            Console.Write("Enter correct operation (+, -, *, /, %): ");
            char operation = (char)Console.Read();

            int result = 0;
            switch (operation)
            {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                case '%':
                    result = num1 % num2;
                    break;
                default: Console.WriteLine("Invalid operation!!");
                    return;
            }

            Console.WriteLine("The answer is " + result.ToString());
        }
    }
}
