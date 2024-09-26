using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassEx4
{
    /*
    // 델리게이트 선언
    public delegate void EnemyAttackHandler(float damage);

    // 적 클래스
    public class Enemy
    {
        // 공격 이벤트
        public event EnemyAttackHandler OnAttack;

        // 적의 공격 메소드
        public void Attack(float damage)
        {
            // 이벤트 호출
            OnAttack?.Invoke(damage); // 플레이어의 HandlerDamage 메소드 호출
        }
    }

    public class Player
    {
        public void HandleDamage(float damage)
        {
            Console.WriteLine("플레이어가 {0}의 데미지를 입었습니다.", damage);
        }
    }
    */
    public class ClassEx4
    {
        static void Main(string[] args)
        {
            Warrior player = new Warrior("Player"); // 플레이어 생성
            Goblin goblin = new Goblin("Goblin"); // 고블린 생성
            Dragon dragon = new Dragon("Dragon"); // 드래곤 생성

            // 각 스테이지의 보상 아이템들
            List<IItem> stage1Rewards = new List<IItem> { new HealthPotion(), new StrengthPotion() };
            List<IItem> stage2Rewards = new List<IItem> { new StrengthPotion(), new HealthPotion() };

            // 스테이지 1
            Stage stage1 = new Stage(player, goblin, stage1Rewards);
            stage1.Start();

            // 스테이지 1이 끝난 후 플레이어가 죽었는지 확인
            if (player.IsDead) return;

            // 스테이지 2
            Stage stage2 = new Stage(player, dragon, stage2Rewards);
            stage2.Start();

            // 스테이지 2가 끝난 후 플레이어가 죽었는지 확인
            if (player.IsDead) return;

            // 게임 클리어
            Console.WriteLine("축하합니다! 모든 스테이지를 클리어했습니다!");
        }
    }
}
