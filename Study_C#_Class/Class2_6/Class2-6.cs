using System;
using System.Collections.Generic;

namespace Class2_6
{

    internal class Class2_6
    {
        static void PrintLine()
        {
            for (int i = 0; i < 10; i++)
            {
                Console.Write("=");
            }
            Console.WriteLine();
        } // 메인 함수가 스태틱이므로 같은 static으로 선언 -> 이유 좀더 자세히 알아보기

        static void PrintLine2(int count)
        {
            for (int i = 0; i < count; i++)
            {
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        static int Add(int a, int b)
        {
            return a + b;
        }

        static int AddNumbers(int a, int b)
        {
            return (a + b);
        }
        static float AddNumbers(float a, float b)
        {
            return (a + b);
        }

        static int AddNumbers(int a, int b, int c)
        {
            return a + b + c;
        }

        static void CountDown(int n) // 재귀함수
        {
            if (n <= 0)
            {
                Console.WriteLine("Done");
            }
            else
            {
                Console.WriteLine(n);
                CountDown(n - 1);  // 자기 자신을 호출
            }
        }

        static void Main(string[] args)
        {
            // ------------------------2-6강. 메서드와 구조체-------------------------
            PrintLine();
            PrintLine2(20);

            // 메소드 반환값 실습
            int result = Add(10, 20);
            Console.WriteLine(result);
            Console.WriteLine();

            // 오버로딩 실습
            int sum1 = AddNumbers(10, 20);
            float sum2 = AddNumbers(10.5f, 21.5f);
            int sum3 = AddNumbers(10, 20, 30);

            // 재귀 메서드 호출
            CountDown(5);
        }
    }
}
