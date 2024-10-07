using System.Drawing;

namespace ClassEx3_1
{
    internal class Program
    {
        /*
        ### 3-1 스네이크

        콘솔 기반의 간단한 뱀 게임을 구현하는 것입니다.기본적인 뱀 게임의 동작 방식은 아래와 같습니다:

        1. 뱀은 매 턴마다 자신의 앞으로 이동합니다.
        2. 사용자는 방향키를 이용하여 뱀의 이동 방향을 제어할 수 있습니다.
        3. 뱀은 맵에 무작위로 생성되는 음식을 먹을 수 있습니다. 뱀이 음식을 먹으면 점수가 올라가고, 뱀의 길이가 늘어납니다.
        4. 뱀이 벽이나 자신의 몸에 부딪히면 게임이 끝나고 'Game Over' 메시지를 출력합니다.
        */
        static void Main(string[] args)
        {
            // 뱀의 초기 위치와 방향을 설정하고, 그립니다.
            Point p = new Point(4, 5, '*');
            Snake snake = new Snake(p, 4, Direction.RIGHT);
            snake.Draw();

            // 음식의 위치를 무작위로 생성하고, 그립니다.
            FoodCreator foodCreator = new FoodCreator(80, 20, '$');
            Point food = foodCreator.CreateFood();
            food.Draw();

            // 게임 루프: 이 루프는 게임이 끝날 때까지 계속 실행됩니다.
            while (true)
            {
                // 키 입력이 있는 경우에만 방향을 변경합니다.
               
                switch(Console.ReadKey().Key)
                {
                    case ConsoleKey.LeftArrow:
                        Console.WriteLine("왼쪽 방향키가 눌렸습니다.");
                        break;
                    case ConsoleKey.RightArrow:
                        Console.WriteLine("오른쪽 방향키가 눌렸습니다.");
                        break;
                    case ConsoleKey.UpArrow:
                        Console.WriteLine("위쪽 방향키가 눌렸습니다.");
                        break;
                    case ConsoleKey.DownArrow:
                        Console.WriteLine("아래쪽 방향키가 눌렸습니다.");
                        break;
                    default:
                        Console.WriteLine("다른 키가 눌렸습니다.");
                        continue;
                        break;
                }

                // 뱀이 이동하고, 음식을 먹었는지, 벽이나 자신의 몸에 부딪혔는지 등을 확인하고 처리하는 로직을 작성하세요.
                // 이동, 음식 먹기, 충돌 처리 등의 로직을 완성하세요.

                Thread.Sleep(100); // 게임 속도 조절 (이 값을 변경하면 게임의 속도가 바뀝니다)

                // 뱀의 상태를 출력합니다 (예: 현재 길이, 먹은 음식의 수 등)
            }
        }
    }
}
