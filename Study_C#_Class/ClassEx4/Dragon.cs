using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassEx4
{
    // 드래곤 클래스
    public class Dragon : Monster
    {
        public Dragon(string name) : base(name, 100) { } // 체력 100
    }
}
