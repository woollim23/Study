using System;
using System.Collections.Generic;

namespace Class2_4
{
    internal class Class2_4
    {
        static void Main(string[] args)
        {
            // ------------------------2-4강. 조건문과 반복문4-------------------------
            // 1) 가위바위보
            string[] choices = { "가위", "바위", "보" };
            string playerChoice = "";
            string computerChoice = choices[new Random().Next(0, 3)]; // 0~2까지만 랜덤 선택

            while (playerChoice != computerChoice)
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

        }
    }
}
