using System;

public class Example
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        
        if(n % 2 == 0)
        {
            Console.WriteLine("{0} is even",n);
        }
        else
        {
            Console.WriteLine("{0} is odd",n);
        }
    }
}