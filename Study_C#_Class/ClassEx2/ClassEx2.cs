using System;
using System.Collections.Generic;
using System.Collections.Specialized;

namespace ClassEx2
{
    internal class ClassEx2
    {
        static void PrintMap(int[,] map) // 맵 그리기 함수
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (map[i, j] == 0)
                        Console.Write("□ ");
                    else if (map[i, j] == 1)
                        Console.Write("● ");
                    else if (map[i, j] == 2)
                        Console.Write("× ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        static bool DecideMap(int[,] map) // 무승부확인
        {
            bool full = false;

            // 빈자리 예외처리
            while (true)
            {
                int count = 0;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (map[i, j] == 0)
                            count++;
                        if ((i == 2 && j == 2) && count == 0)
                        {
                            full = true;
                        }
                    }
                }
                if (count != 0)
                    break;
            }


            return full;
        }
        static int DecideWin(int[,] map) // 무승부확인
        { 
            int win = 0;

            // 승리 예외처리
            for (int i = 0; i < 3; i++)
            {
                if ((map[i, 0] == map[i, 1] && map[i, 1] == map[i, 2]) && map[i, 0] != 0)
                    win = map[i, 0];
                if ((map[0, i] == map[1, i] && map[1, i] == map[2, i]) && map[0, i] != 0)
                    win = map[0, i];
            }
            if ((map[0, 0] == map[1, 1] && map[1, 1] == map[2, 2]) && map[2, 2] != 0)
                win = map[0, 0];
            if ((map[2, 0] == map[1, 1] && map[1, 1] == map[0, 2]) && map[0, 2] != 0)
                win = map[2, 0];

            return win;
        }

        static void Main(string[] args)
        {
            // -----------2주차 숙제-------------

            /* 문제 1
             * 숫자 맞추기 게임 만들기
             * [지시사항]
             * 여기에 코드를 입력해주세요:)
             */
            int targetNumber = new Random().Next(1, 101); // 1~100
            int guess = 0;
            int count = 0;
            Console.WriteLine("1부터 100 사이의 숫자를 맞춰보세요.");

            while (guess != targetNumber)
            {
                Console.Write("추측한 숫자를 입력하세요 : ");
                guess = int.Parse(Console.ReadLine());
                count++;

                if (guess < targetNumber)
                {
                    Console.WriteLine("좀 더 큰 숫자를 입력하세요. UP↑");
                }
                else if (guess > targetNumber)
                {
                    Console.WriteLine("좀 더 작은 숫자를 입력하세요. DOWN↓");
                }
                else
                {
                    Console.WriteLine($"축하합니다! 숫자를 맞추셨습니다. 정답은 \"{targetNumber}\" 입니다.");
                    Console.WriteLine("시도한 횟수 : " + count + " 회");
                }
            }

            /* 문제 2
             * 틱택토 게임 만들기
             * [지시사항]
             * 여기에 코드를 입력해주세요:)
             */
            int winner = 0; // 1은 플레이어, 2는 컴퓨터
            int[,] map = new int[3, 3]
            {
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
            };

            Console.WriteLine("3 * 3 틱택톡 게임입니다. 좌표를 선택해 주세요. ");
            // 초기 맵 그리기
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Console.Write("□ ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();


            // 게임 진행
            while (winner == 0)
            {
                // 플레이어가 고르는 타임
                int PlayerX;
                int PlayerY;
                while(true)
                {
                    try
                    {
                        Console.Write("X 좌표를 선택하세요.(X : 0~2) : ");
                        PlayerX = int.Parse(Console.ReadLine());
                        Console.Write("Y 좌표를 선택하세요.(Y : 0~2) : ");
                        PlayerY = int.Parse(Console.ReadLine());

                        if ((PlayerX < 0) || (PlayerY < 0) || (PlayerX > 2) || (PlayerY > 2))
                        {
                            Console.WriteLine("입력한 좌표가 범위를 벗어났습니다. 다시 입력해주세요.");
                        }
                        else if (map[PlayerX, PlayerY] == 2)
                        {
                            Console.WriteLine("이미 선택된 좌표입니다. 다른 좌표를 선택해주세요.");
                        }
                        else
                        {
                            break;
                        }
                    }
                    catch (FormatException) // C#에 이미 있는 포맷 입력한 데이터 형식이 잘못 되었을 때 실행
                    {
                        Console.WriteLine("잘못된 입력입니다. 숫자를 입력해주세요.");
                    }
                    catch (IndexOutOfRangeException) // 인덱스 유효 범위를 벗어났을 때 실행
                    {
                        Console.WriteLine("입력한 좌표가 범위를 벗어났습니다. 다시 입력해주세요.");
                    }

                    Console.WriteLine();
                }
                
                map[PlayerX, PlayerY] = 1;

                PrintMap(map);
                if (DecideMap(map) == true || DecideWin(map) != 0)
                    break;

                // 컴퓨터가 고르는 타임
                int ComputerX;
                int ComputerY;
                do
                {
                    ComputerX = new Random().Next(0, 3);
                    ComputerY = new Random().Next(0, 3);
                }while(map[ComputerX, ComputerY] == 1);

                map[ComputerX, ComputerY] = 2;
                Console.WriteLine($"컴퓨터가 선택했습니다.");
                Console.WriteLine();

                PrintMap(map);
                if (DecideMap(map) == true || DecideWin(map) != 0)
                    break;
            }

            winner = DecideWin(map);

            if (winner == 0)
                Console.WriteLine("무승부 입니다.");
            else if (winner == 1)
                Console.WriteLine("승리하셨습니다!");
            else if (winner == 2)
                Console.WriteLine("패배하셨습니다..");
        }
    }
}