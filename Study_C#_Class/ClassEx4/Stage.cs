using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassEx4
{
    // 스테이지 클래스
    public class Stage
    {
        private ICharacter player; // 플레이어
        private ICharacter monster; // 몬스터
        private List<IItem> rewards; // 보상 아이템들

        // 이벤트 델리게이트 정의
        public delegate void GameEvent(ICharacter character);
        public event GameEvent OnCharacterDeath; // 캐릭터가 죽었을 때 발생하는 이벤트

        public Stage(ICharacter player, ICharacter monster, List<IItem> rewards)
        {
            this.player = player;
            this.monster = monster;
            this.rewards = rewards;
            OnCharacterDeath += StageClear; // 캐릭터가 죽었을 때 StageClear 메서드 호출
        }

        // 스테이지 시작 메서드
        public void Start()
        {
            Console.WriteLine($"스테이지 시작! 플레이어 정보: 체력({player.Health}), 공격력({player.Attack})");
            Console.WriteLine($"몬스터 정보: 이름({monster.Name}), 체력({monster.Health}), 공격력({monster.Attack})");
            Console.WriteLine("----------------------------------------------------");

            while (!player.IsDead && !monster.IsDead) // 플레이어나 몬스터가 죽을 때까지 반복
            {
                // 플레이어의 턴
                Console.WriteLine($"{player.Name}의 턴!");
                monster.TakeDamage(player.Attack);
                Console.WriteLine();
                Thread.Sleep(1000);  // 턴 사이에 1초 대기

                if (monster.IsDead) break;  // 몬스터가 죽었다면 턴 종료

                // 몬스터의 턴
                Console.WriteLine($"{monster.Name}의 턴!");
                player.TakeDamage(monster.Attack);
                Console.WriteLine();
                Thread.Sleep(1000);  // 턴 사이에 1초 대기
            }

            // 플레이어나 몬스터가 죽었을 때 이벤트 호출
            if (player.IsDead)
            {
                OnCharacterDeath?.Invoke(player);
            }
            else if (monster.IsDead)
            {
                OnCharacterDeath?.Invoke(monster);
            }
        }

        // 스테이지 클리어 메서드
        private void StageClear(ICharacter character)
        {
            if (character is Monster)
            {
                Console.WriteLine($"스테이지 클리어! {character.Name}를 물리쳤습니다!");

                // 플레이어에게 아이템 보상
                if (rewards != null)
                {
                    Console.WriteLine("아래의 보상 아이템 중 하나를 선택하여 사용할 수 있습니다:");
                    foreach (var item in rewards)
                    {
                        Console.WriteLine(item.Name);
                    }

                    Console.WriteLine("사용할 아이템 이름을 입력하세요:");
                    string input = Console.ReadLine();

                    // 선택된 아이템 사용
                    IItem selectedItem = rewards.Find(item => item.Name == input);
                    if (selectedItem != null)
                    {
                        selectedItem.Use((Warrior)player);
                    }
                }

                player.Health = 100; // 각 스테이지마다 체력 회복
            }
            else
            {
                Console.WriteLine("게임 오버! 패배했습니다...");
            }
        }
    }
}
