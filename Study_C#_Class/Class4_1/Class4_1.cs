using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Class4_1
{
    internal class Class4_1
    {
        // 인터페이스 구현해보기
        public interface IMovable
        {
            void Move(int x, int y);

        }

        public class Player : IMovable
        {
            public void Move(int x, int y)
            {
                // 플레이어 움직임 구현
            }
        }
        public class Enemy : IMovable
        {
            public void Move(int x, int y)
            {
                // 적 움직임 구현
            }
        }

        public interface IUsable
        {
            void Use();
        }

        public class Item : IUsable
        {
            public string Name { get; set; }

            public void Use()
            {
                Console.WriteLine("아이템 {0}을 사용했습니다.", Name);
            }
        }

        public class PlayerUse
        {
            public void UseItem(IUsable item)
            {
                item.Use();
            }
        }

        public enum Month
        {
            Jan = 1,
            Feb,
            Mar,
            Apr,
            May,
            Jun,
            Jul,
            Aug,
            Sep,
            Oct,
            Nov,
            Dec
        }

        public static void ProsessMonth(int month)
        {
            if (month >= (int)Month.Jan && month <= (int)Month.Dec)
            {
                Month selectMonth = (Month)month;
                Console.WriteLine("선택한 월은 {0}입니다.", selectMonth);
            }
            else
            {
                Console.WriteLine("올바른 월을 입력해주세요.");
            }
        }

        static void Main(string[] args)
        {
            // 인터페이스명 인스턴스명 = new 클래스명();
            IMovable movableObject1 = new Player();
            IMovable movableObject2 = new Enemy();

            movableObject1.Move(1, 2);
            movableObject1.Move(1, 9);

            PlayerUse pu = new PlayerUse();
            Item item = new Item() { Name = "Health Position" };
            pu.UseItem(item);

            int userInput = 7;
            ProsessMonth(userInput);
        }
    }
}
