﻿using System;
using System.Collections.Generic;

namespace Class2_1
{
    internal class Class2_1
    {
        static void Main(string[] args)
        {
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


        }
    }
}
