using System;

namespace Question_3
{
    public delegate void TrafficDel();
    class Program
    {
        static void Main(string[] args)
        {
            TrafficSignal ts = new TrafficSignal();
            TrafficDel currentSignal = ts.Green;
            currentSignal();
            currentSignal = ts.Yellow;
            currentSignal();
            currentSignal = ts.Red;
            currentSignal();
        }
    }

    public class TrafficSignal
    {
        public void Yellow()
        {
            Console.WriteLine("Slow Down!!");
        }

        public void Red()
        {
            Console.WriteLine("Stop!!");
            
        }

        public void Green()
        {
            Console.WriteLine("GOOOOO!!");
        }
    }
}
