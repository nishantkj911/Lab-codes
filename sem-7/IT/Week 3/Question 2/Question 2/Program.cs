using System;

namespace Question_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Item i = new Item
            {
                Name = "Sushi",
            };

            Console.WriteLine("The tax for the item " + i.Name + " is $" + i.CalcGST());
        }
    }

    public class Item
    {
        public string Name { get; set; }
        private static decimal cost =(decimal) 10.0;
        // Shared variable - Static (doesn't make sense, but have to do it...)
        public static decimal Cost
        {
            get => cost; set => cost = value;
        }

        public decimal CalcGST(decimal taxRate =(decimal) 0.08)
        {
            return Cost * taxRate;
        }

    }
}
