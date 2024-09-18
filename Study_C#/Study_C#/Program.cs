using System;

namespace Study_C_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*
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
            Console.WriteLine("{0:0.#0}",num);

            // BMI 계산기 만들기
            // [지시사항]
            // BMI 지수를 계산하는 프로그램을 만들어봅시다
            Console.WriteLine("키(cm)를 입력하시오 : ");
            double H = Convert.ToDouble(Console.ReadLine()) / 100;
            Console.WriteLine("몸무게(kg)를 입력하시오 : ");
            double W = Convert.ToDouble(Console.ReadLine());
            double res = W / (H * H);
            Console.WriteLine("{0:0.#0}", res);
            */

            // ------------------------1-1강. C#소개, 개발 환경 설정-------------------------
            Console.WriteLine("Hello, World!");

            // 1. 클래스, 메서드, 변수 등의 이름을 입력할 때 일부를 입력하고, Tab 키를 눌러 나머지를 자동 완성합니다.
            // - Console.WriteLine을 작성할 때, Console. 까지 입력하고 Tab 키를 누르면 자동으로 WriteLine이 완성됩니다.
            Console.WriteLine("C#");

            // - 메서드나 변수를 입력하는 도중에 Ctrl + Space를 눌러 IntelliSense를 호출하면, 해당 메서드나 변수에 대한 정보와 예제를 볼 수 있습니다.
            Console.WriteLine("Study\n");

            // 2. 코드 템플릿을 사용하며 코드를 더 빠르게 작성합니다.
            // - 예를 들어, for문을 작성할 때, for 키워드를 입력하고, 두 번 Tab 키를 누르면 for문의 기본적인 코드 템플릿이 자동으로 생성됩니다.

            // 연습해보기
            // 1. Visual Studio에서 새로운 C# 콘솔 애플리케이션 프로젝트를 생성하고, Hello World 메시지를 출력하는 프로그램 작성해보기
            // 2. 자동완성 기능과 Intellisense를 사용하여 C# 콘솔 애플리케이션을 작성해보기
            // 3. Debug 모드와 Release 모드 각각으로 프로젝트를 빌드하고 실행하여 차이점을 이해하기


            // ------------------------1-2강. 프로그래밍 기본 요소-------------------------
            Console.WriteLine("My Name is Woollim");
            Console.WriteLine(10);
            Console.WriteLine(3.141592);
            Console.WriteLine(3 + 3);

            Console.Write("Hello! ");
            Console.Write("We are Learning ");
            Console.WriteLine("at TeamSparta\n");


            // ------------------------1-4강. 변수와 자료형2-------------------------
            // 주석 단축키 : Ctrl K C
            //Console.Write("Enter your name: ");
            //string name = Console.ReadLine();
            //Console.WriteLine("Hello, {0}!", name);
            // 주석 해제 단축키 : Ctrl K U

            //Console.Write("Enter two numbers: ");
            //string input = Console.ReadLine();    // "10 20"과 같은 문자열을 입력받음

            //string[] numbers = input.Split(' ');  // 문자열을 공백으로 구분하여 배열로 만듦
            //int n1 = int.Parse(numbers[0]);     // 첫 번째 값을 정수로 변환하여 저장
            //int n2 = int.Parse(numbers[1]);     // 두 번째 값을 정수로 변환하여 저장

            //int sum = n1 + n2;                // 두 수를 더하여 결과를 계산

            //Console.WriteLine("The sum of {0} and {1} is {2}.\n", n1, n2, sum);


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
            Console.WriteLine(string.Compare(str1,str2));

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