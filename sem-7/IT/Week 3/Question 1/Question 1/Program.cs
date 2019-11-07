using System;

namespace Question_1
{
    public delegate void PriceChangedEventDelegate(decimal a, decimal b);
    class Program
    {
        static void Main(string[] args)
        {
            Item i = new Item("Electronics", (decimal)20.4, eventBody);
            i.Price = (decimal)19.4;
            i.Price = (decimal)21.0;

            i.priceChangedEvent = eventBody2;
            i.Price = (decimal)29.0;

        }

        static void eventBody(decimal from, decimal to)
        {
            Console.WriteLine("The price has been changed from " + from + " to " + to);
        }

        static void eventBody2(decimal a, decimal b)
        {
            Console.WriteLine((a + b).ToString());
        }
    }

    public class Item
    {
        public Item(string n, decimal p, PriceChangedEventDelegate e)
        {
            Name = n;
            Price = p;
            priceChangedEvent = e;
            Console.WriteLine("And Item object has been declared...");
        }
        private string name;
        private decimal price;
        public PriceChangedEventDelegate priceChangedEvent;

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }

        public decimal Price
        {
            get
            {
                return price;
            }
            set
            {
                priceChangedEvent?.Invoke(price, value);
                price = value;
            }
        }
    }
}
