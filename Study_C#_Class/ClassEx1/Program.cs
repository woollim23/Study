using System;
using System.Collections.Generic;

namespace ClassEx1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // -----------1주차 숙제-------------
            // 사용자로부터 입력 받기
            // [지시사항]
            // 이름과 나이를 입력 받고 출력하는 코드를 작성하세요
            Console.WriteLine("이름과 나이를 입력 하시오(이름 나이) : ");
            string str = Console.ReadLine();

            string[] str2 = str.Split(' ');
            Console.WriteLine($"{str2[0]} {str2[1]}");

            // 간단한 사칙연산 계산기 만들기
            // [지시사항]
            // 두 수를 입력 받고 사칙연산의 결과를 출력하세요
            int num_1, num_2;
            string str0 = Console.ReadLine();
            string[] str0_1 = str0.Split(' ');
            num_1 = int.Parse(str0_1[0]);
            num_2 = int.Parse(str0_1[1]);
            Console.WriteLine(num_1 + num_2);

            // 온도 변환기 만들기
            // [지시사항]
            // 섭씨온도를 화씨온도로 변환하는 프로그램을 만들어주세요
            double num = double.Parse(Console.ReadLine());
            num = (num * 1.8) + 32;
            Console.WriteLine("{0:0.#0}", num);

            // BMI 계산기 만들기
            // [지시사항]
            // BMI 지수를 계산하는 프로그램을 만들어봅시다
            Console.WriteLine("키(cm)를 입력하시오 : ");
            double H = Convert.ToDouble(Console.ReadLine()) / 100;
            Console.WriteLine("몸무게(kg)를 입력하시오 : ");
            double W = Convert.ToDouble(Console.ReadLine());
            double res = W / (H * H);
            Console.WriteLine("{0:0.#0}", res);
        }
    }

}