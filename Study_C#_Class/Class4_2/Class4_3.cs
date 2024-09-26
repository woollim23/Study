using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Class4_3
{
    internal class Class4_3
    {
        // 델리게이트 예제
        delegate void MyDelegate(string message);

        static void Method1(string message)
        {
            Console.WriteLine("Method1: " + message);
        }

        static void Method2(string message)
        {
            Console.WriteLine("Method2: " + message);
        }

        // 펑크, 액션 예제 
        static int Add(int x, int y)
        {
            return x + y;
        }

        static void PrintMessage(string message)
        {
            Console.WriteLine(message);
        }

        static void Main(string[] args)
        {
            // 델리게이트 예제
            MyDelegate myDelegate = Method1;
            myDelegate += Method2;

            myDelegate("Hello!");

            // 펑크, 액션 예제
            Func<int, int, int> addFunc = Add;
            Console.WriteLine(addFunc(3, 5)); // 8

            Action<string> printAction = PrintMessage;
            printAction("Hello, World!"); // Hello, World!

        }
    }
}
