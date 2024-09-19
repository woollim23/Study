using System;
using System.Collections.Generic;

namespace Study_C_
{
    internal class Program
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
            /*
             *  1주차 학습 강의
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
            */

            /*
             * 2주차 학습강의
            // ------------------------2-1강. 조건문과 반복문1-------------------------
            // 코드 스니펫 if문
            int playerScore = 80;

            if (playerScore >= 70)
            {
                Console.WriteLine("플레이어의 점수는 70점 이상입니다. 합격입니다!");
            }
            Console.WriteLine("프로그램이 종료됩니다.");
            Console.WriteLine();

            // 코드 스니펫 else문
            int itemCount = 5;
            string itemName = "HP 포션";

            if (itemCount > 0)
            {
                Console.WriteLine($"보유한 {itemName}의 수량: {itemCount}");
            }
            else
            {
                Console.WriteLine($"보유한 {itemName}이 없습니다.");
            }
            Console.WriteLine();

            // else if 실습
            Console.Write("플레이어 랭크를 입력하세요.(0~100) : ");
            int score = int.Parse(Console.ReadLine());
            string playerRank = "";
            Console.WriteLine(score);
            
            if (score >= 90)
            {
                playerRank = "Diamond";
            }
            else if (score >= 80)
            {
                playerRank = "Platinum";
            }
            else if (score >= 70)
            {
                playerRank = "Gold";
            }
            else if (score >= 60)
            {
                playerRank = "Silver";
            }
            else
            {
                playerRank = "Bronze";
            }

            Console.WriteLine("플레이어의 등급은 {0} 입니다.", playerRank);
            Console.WriteLine();

            // 코드스니펫 switch문 기초
            Console.WriteLine("게임을 시작합니다.");
            Console.WriteLine("1: 전사 / 2: 마법사 / 3: 궁수");
            Console.Write("직업을 선택하세요: ");
            string job = Console.ReadLine();

            switch (job)
            {
                case "1":
                    Console.WriteLine("전사를 선택하셨습니다.");
                    break;
                case "2":
                    Console.WriteLine("마법사를 선택하셨습니다.");
                    break;
                case "3":
                    Console.WriteLine("궁수를 선택하셨습니다.");
                    break;
                default:
                    Console.WriteLine("올바른 값을 입력해주세요.");
                    break;
            }

            Console.WriteLine("게임을 종료합니다.");
            Console.WriteLine();
         

            // ------------------------2-2강. 조건문과 반복문2-------------------------
            // 1) 홀수 / 짝수 구분하기
            Console.Write("번호를 입력하세요 : ");
            int number = int.Parse(Console.ReadLine());

            if (number % 2 == 0)
            {
                Console.WriteLine("짝수입니다.");
            }
            else
            {
                Console.WriteLine("홀수입니다.");
            }

            // 2) 등급 출력
            int playerScore = 100;
            string playerRank = "";

            switch (playerScore / 10)
            {
                case 10:
                case 9:
                    playerRank = "Diamond";
                    break;
                case 8:
                    playerRank = "Platinum";
                    break;
                case 7:
                    playerRank = "Gold";
                    break;
                case 6:
                    playerRank = "Silver";
                    break;
                default:
                    playerRank = "Bronze";
                    break;
            }
            Console.WriteLine(playerRank);

            // 3) 로그인 프로그램
            string id = "id";
            string password = "pw";

            Console.Write("아이디를 입력하세요 : ");
            string inputId = Console.ReadLine();
            Console.Write("비밀번호를 입력하세요 : ");
            string inputPassword = Console.ReadLine();

            if (id == inputId && password == inputPassword)
            {
                Console.WriteLine("로그인 성공!");
            }
            else
            {
                Console.WriteLine("로그인 실패...");
            }


            // 4) 알파벳 판별 프로그램
            Console.Write("문자를 입력하세요 : ");
            char input = Console.ReadLine()[0];

            if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
            {
                Console.WriteLine("알파벳 입니다.");
            }
            else
            {
                Console.WriteLine("알파벳이 아닙니다.");
            }
            

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

            
            // ------------------------2-4강. 조건문과 반복문4-------------------------
            // 1) 가위바위보
            string[] choices = { "가위", "바위", "보" };
            string playerChoice = "";
            string computerChoice = choices[new Random().Next(0, 3)]; // 0~2까지만 랜덤 선택

            while(playerChoice != computerChoice)
            {
                Console.Write("가위, 바위, 보 중 하날 선택하시오 : ");
                playerChoice = Console.ReadLine();

                if (playerChoice == computerChoice)
                {
                    Console.WriteLine("비겼습니다");
                }
                else if (playerChoice == "가위")
                {
                    if (computerChoice == "보")
                        Console.WriteLine("플레이어 승리!");
                    else
                        Console.WriteLine("컴퓨터 승리!");
                }
                else if (playerChoice == "바위")
                {
                    if (computerChoice == "가위")
                        Console.WriteLine("플레이어 승리!");
                    else
                        Console.WriteLine("컴퓨터 승리!");
                }
                else if (playerChoice == "보")
                {
                    if (computerChoice == "바위")
                        Console.WriteLine("플레이어 승리!");
                    else
                        Console.WriteLine("컴퓨터 승리!");
                }
            }
            Console.WriteLine();

            // 2) 숫자 맞추기
            int targetNumber = new Random().Next(1, 101); // 1~100
            int guess = 0;
            int count = 0;
            Console.WriteLine("1부터 100 사이의 숫자를 맞춰보세요.");

            while (guess != targetNumber)
            {
                Console.WriteLine("추측한 숫자를 입력하세요 : ");
                guess = int.Parse(Console.ReadLine());
                count++;

                if (guess < targetNumber)
                {
                    Console.WriteLine("좀 더 큰 숫자를 입력하세요.");
                }
                else if (guess > targetNumber)
                {
                    Console.WriteLine("좀 더 작은 숫자를 입력하세요.");
                }
                else
                {
                    Console.WriteLine("축하합니다! 숫자를 맞추셨습니다.");
                    Console.WriteLine("시도한 횟수 : " + count);
                }
            }
            

            // ------------------------2-5강. 배열과 컬렉션-------------------------

            // 2) 게임 캐릭터의 능력치 배열 만들기
            // 플레이어의 공격력, 방어력, 체력, 스피드를 저장할 배열
            int[] playerStats = new int[4];

            // 능력치를 랜덤으로 생성하여 배열에 저장
            Random rand = new Random();
            for (int i = 0; i < playerStats.Length; i++)
            {
                playerStats[i] = rand.Next(1, 11); // 1~10
            }

            // 능력치 출력
            Console.WriteLine("플레이어의 공격력: " + playerStats[0]);
            Console.WriteLine("플레이어의 방어력: " + playerStats[1]);
            Console.WriteLine("플레이어의 체력: " + playerStats[2]);
            Console.WriteLine("플레이어의 스피드: " + playerStats[3]);
            Console.WriteLine();

            // 3) 학생들의 성적 평균 구하기
            int[] scores = new int[5];

            for (int i = 0; i < scores.Length; i++)
            {
                Console.Write("학생 " + (i + 1) + " 의 성적을 입력하세요 : ");
                scores[i] = int.Parse(Console.ReadLine());
            }

            int sum = 0;
            for (int i = 0; i < scores.Length; i++)
            {
                sum += scores[i];
            }

            double average = (double)sum / scores.Length;
            Console.WriteLine("성적 평균은 " + average + " 입니다.");

            // [코드스니펫] 배열을 활용한 숫자 맞추기 게임
            Random random = new Random();  // 랜덤 객체 생성
            int[] numbers = new int[3];  // 3개의 숫자를 저장할 배열

            // 3개의 랜덤 숫자 생성하여 배열에 저장
            for (int i = 0; i < numbers.Length; i++)
            {
                numbers[i] = random.Next(1, 10);
            }

            int attempt = 0;  // 시도 횟수 초기화
            while (true)
            {
                Console.Write("3개의 숫자를 입력하세요 (1~9): ");
                int[] guesses = new int[3];  // 사용자가 입력한 숫자를 저장할 배열

                for (int i = 0; i < guesses.Length; i++)
                {
                    guesses[i] = int.Parse(Console.ReadLine());
                }

                int correct = 0;

                for (int i = 0; i < numbers.Length; i++)
                {
                    for (int j = 0; j < guesses.Length; j++)
                    {
                        if (numbers[i] == guesses[j])
                        {
                            correct++;
                            break;
                        }
                    }
                }

                attempt++;
                Console.WriteLine("시도 #" + attempt + " : " + correct + "개의 숫자를 맞추셨습니다.");

                if (correct == 3)
                {
                    Console.WriteLine("축하합니다. 모든 숫자를 맞추셨습니다.");
                    break;
                }
            }

            // 6) 2차월 배열을 사용하여 게임 맵을 구현
            int[,] map = new int[5, 5]
            {
                {1, 1, 1, 1, 1},
                {1, 0, 0, 0, 1},
                {1, 0, 1, 0, 1},
                {1, 0, 0, 0, 1},
                {1, 1, 1, 1, 1}
            };


            for(int i = 0; i<5;i++)
            {
                for(int j =0; j<5;j++)
                {
                    if (map[i,j]==1)
                    {
                        Console.Write("■ ");
                    }
                    else
                    {
                        Console.Write("▤ ");
                    }
                }
                Console.WriteLine();
            }


            // 7) 컬렉터 - 리스트
            List<int> list = new List<int>();
            list.Add(1);
            list.Add(2);
            list.Add(3);

            list.Remove(2);

            for(int i =0;i<list.Count;i++)
            {
                Console.WriteLine(list[i]);
            }

            foreach (int i in list)
            {
                Console.WriteLine(i);
            }
            */


            // ------------------------2-6강. 메서드와 구조체1-------------------------
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