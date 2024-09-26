using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassEx4
{
    // 고블린 클래스
    public class Goblin : Monster
    {
        public Goblin(string name) : base(name, 50) { } // 체력 50
    }
}
