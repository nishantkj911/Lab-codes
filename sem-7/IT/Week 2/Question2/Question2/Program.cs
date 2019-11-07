using System;

namespace Question2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a date ('DD-MM-YYYY HH:mm:ss')");
            string s = Console.ReadLine();
            long[] completeDateFormat = new long[6];

            //parsing all the values.
            long.TryParse(s.Substring(0, 2), out completeDateFormat[2]);
            long.TryParse(s.Substring(3, 2), out completeDateFormat[1]);
            long.TryParse(s.Substring(6, 4), out completeDateFormat[0]);
            long.TryParse(s.Substring(11, 2), out completeDateFormat[3]);
            long.TryParse(s.Substring(14, 2), out completeDateFormat[4]);
            long.TryParse(s.Substring(17, 2), out completeDateFormat[5]);

            Console.WriteLine("Enter the no. of ticks (1 tick = 100 ns)");
            Int64 ticks = Convert.ToInt64(Console.ReadLine());
            Int64 temp = ticks / 10000000;

            for (int i = 5; i >= 0; i--)
            {
                completeDateFormat[i] += temp;
                if (i == 0)
                    break;
                int x = 1;
                if (i == 5 || i == 4)
                    x = 60;
                else if (i == 3)
                    x = 24;
                else if (i == 2)
                {
                    long month = completeDateFormat[i] - temp;
                    if ((month < 8 && month % 2 == 1) || (month >= 8 && month % 2 == 0))
                        x = 31;
                    else if (month != 2)
                        x = 30;
                    else
                    {
                        if (completeDateFormat[0] % 4 == 0)
                        {
                            if (completeDateFormat[0] % 100 == 0)
                            {
                                if (completeDateFormat[0] % 400 == 0)
                                    x = 29;
                                else
                                {
                                    x = 28;
                                }
                            }
                            else
                                x = 29;
                        }
                        else
                        {
                            x = 28;
                        }
                    }
                }
                else if (i == 1)
                    x = 12;

                Console.WriteLine("Temp: " + temp);
                Console.WriteLine(completeDateFormat[i]);
                Console.WriteLine("x: " + x);
                temp = completeDateFormat[i] / x;
                completeDateFormat[i] %= x;
            }

            Console.WriteLine("The new date is: " + completeDateFormat[2] + "-" + completeDateFormat[1] + "-" + completeDateFormat[0] + " " + completeDateFormat[3] + ":" + completeDateFormat[4] + ":" + completeDateFormat[5]);
            Console.Read();
        }
    }
}