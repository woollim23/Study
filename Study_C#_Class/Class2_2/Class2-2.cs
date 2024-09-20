using System;
using System.Collections.Generic;

namespace Class2_2
{
    internal class Class2_2
    {
        static void Main(string[] args)
        {
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
        }
    }
}
