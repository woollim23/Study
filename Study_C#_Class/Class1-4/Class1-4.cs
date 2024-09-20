using System;
using System.Collections.Generic;

namespace Class1_4
{
    internal class Class1_4
    {
        static void Main(string[] args)
        {
            // ------------------------1-4강. 변수와 자료형2-------------------------
            // 주석 단축키 : Ctrl K C
            Console.Write("Enter your name: ");
            string name = Console.ReadLine();
            Console.WriteLine("Hello, {0}!", name);
            // 주석 해제 단축키 : Ctrl K U

            Console.Write("Enter two numbers: ");
            string input = Console.ReadLine();    // "10 20"과 같은 문자열을 입력받음

            string[] numbers = input.Split(' ');  // 문자열을 공백으로 구분하여 배열로 만듦
            int n1 = int.Parse(numbers[0]);     // 첫 번째 값을 정수로 변환하여 저장
            int n2 = int.Parse(numbers[1]);     // 두 번째 값을 정수로 변환하여 저장

            int sum = n1 + n2;                // 두 수를 더하여 결과를 계산

            Console.WriteLine("The sum of {0} and {1} is {2}.\n", n1, n2, sum);
        }
    }
}
