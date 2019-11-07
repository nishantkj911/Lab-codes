using System;

namespace ExampleProject
{
    class Program
    {
        static void Main(string[] _)
        {
            Console.WriteLine("Hello World!");
            string[] arr = { "nishant", "dishari", "abcdef" };
            int[,] mat = new int[3, 3];
            mat[0, 2] = 191;
            int num = mat[0, 2];
            Console.WriteLine(num);
            
        }
    }
}
