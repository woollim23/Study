using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassEx4
{
    // 아이템 인터페이스 정의
    public interface IItem
    {
        string Name { get; }
        void Use(Warrior warrior); // 전사에게 아이템을 사용하는 메서드
    }
}
