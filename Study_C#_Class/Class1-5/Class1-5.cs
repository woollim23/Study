using System;
using System.Collections.Generic;

namespace Class1_5
{
    internal class Class1_5
    {
        static void Main(string[] args)
        {
            // ------------------------1-5강. 연산자와 문자열 처리-------------------------
            int num1 = 20, num2 = 10;

            Console.WriteLine("산술연산자");
            Console.WriteLine(num1 + num2);
            Console.WriteLine(num1 - num2);
            Console.WriteLine(num1 / num2);
            Console.WriteLine(num1 * num2);
            Console.WriteLine(num1 % num2);
            Console.WriteLine();

            Console.WriteLine("관계연산자");
            Console.WriteLine(num1 == num2);
            Console.WriteLine(num1 != num2);
            Console.WriteLine(num1 > num2);
            Console.WriteLine(num1 < num2);
            Console.WriteLine(num1 >= num2);
            Console.WriteLine(num1 <= num2);
            Console.WriteLine();

            Console.WriteLine("논리연산자");
            int num3 = 15;
            Console.WriteLine(0 <= num3 && num3 <= 20);
            Console.WriteLine(0 > num3 || num3 > 20);
            Console.WriteLine(!(0 <= num3 && num3 <= 20));
            Console.WriteLine();


            string str1 = "Hello, World!";
            string str2 = new string('H', 5);

            // 결합
            string str3 = str1 + " " + str2;
            Console.WriteLine(str3);

            // 분할
            string[] str4 = str1.Split(',');
            Console.WriteLine(str4[0]);
            Console.WriteLine(str4[1]);

            // 검색
            int index = str1.IndexOf("World");
            Console.WriteLine(index);

            // 대체
            string newStr = str1.Replace("World", "Universe");
            Console.WriteLine(newStr);
            Console.WriteLine(str1);

            // 변환
            string str5 = "123";
            int num = int.Parse(str5);
            Console.WriteLine(num);

            num += 10;

            Console.WriteLine(num.ToString());

            // 비교
            Console.WriteLine(str1 == str2);
            Console.WriteLine(string.Compare(str1, str2));

            // 포맷팅
            string name = "John";
            int age = 30;
            string messege = string.Format("My name is {0} and I'm {1} years old.", name, age);
            Console.WriteLine(messege);
            string message2 = $"My name is {name} and I'm {age} years old.";
            Console.WriteLine(message2);
        }
    }
}
