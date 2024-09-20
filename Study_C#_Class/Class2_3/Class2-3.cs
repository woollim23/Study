using System;
using System.Collections.Generic;

namespace Class2_3
{
    internal class Class2_3
    {
        static void Main(string[] args)
        {
            // ------------------------2-3강. 조건문과 반복문3-------------------------
            // [코드스니펫] for 문 기초
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(i);
            }

            // [코드스니펫] while 문 기초
            int a = 0;
            while (a < 10)
            {
                Console.WriteLine(a);
                a++;
            }

            // [코드스니펫] 구구단 출력
            for (int i = 1; i <= 9; i++)
            {
                for (int j = 2; j <= 9; j++)
                {
                    Console.Write(j + " x " + i + " = " + (i * j) + "\t");
                }
                Console.WriteLine();
            }

            // [코드스니펫] break와 continue 기초
            for (int i = 1; i <= 10; i++)
            {
                if (i % 3 == 0)
                {
                    continue; // 3의 배수인 경우 다음 숫자로 넘어감
                }

                Console.WriteLine(i);
                if (i == 7)
                {
                    break; // 7이 출력된 이후에는 반복문을 빠져나감
                }
            }

            // [코드스니펫] break와 continue 예제
            int sum = 0;

            while (true)
            {
                Console.Write("숫자를 입력하세요: ");
                int input = int.Parse(Console.ReadLine());

                if (input == 0)
                {
                    Console.WriteLine("프로그램을 종료합니다.");
                    break;
                }

                if (input < 0)
                {
                    Console.WriteLine("음수는 무시합니다.");
                    continue;
                }

                sum += input;
                Console.WriteLine("현재까지의 합: " + sum);
            }

            Console.WriteLine("합계: " + sum);

        }
    }
}
