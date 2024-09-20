// ------------------------3-1강. 8강 클래스와 객체-------------------------
/*
- 6) 구조체 vs 클래스
    - 구조체와 클래스는 모두 사용자 정의 형식을 만드는 데 사용될 수 있습니다.
    - 구조체는 값 형식이며, 스택에 할당되고 복사될 때 값이 복사됩니다. -> 사용자가 아닌 컴퓨터가 자동으로 할당
    - 클래스는 참조 형식이며, 힙에 할당되고 참조로 전달되므로 성능 측면에서 다소 차이가 있습니다. -> 동적할당, 프로그램이 동작을 하고 있을때 공간을 할당 받음
    - 구조체는 상속을 받을 수 없지만 클래스는 단일 상속 및 다중 상속이 가능하다.
    - 구조체는 작은 크기의 데이터 저장이나 단순한 데이터 구조에 적합하며, 클래스는 더 복잡한 객체를 표현하고 다양한 기능을 제공하기 위해 사용됩니다.
*/

using System;
using System.Collections.Generic;

namespace Class3_1
{
    internal class Class3_1
    {

        class Person
        {
            public string name;
            public int age;

            // 디폴트 생성자
            public Person()
            {
                name = "UnKnown";
                age = 0;
                Console.WriteLine("Person 객체 생성");
            }

            public Person(string newName, int newAge)
            {
                name = newName;
                age = newAge;
                Console.WriteLine("Person 객체 생성");
            }

            public void PrintInfo()
            {
                Console.WriteLine("Name : " + name);
                Console.WriteLine("Age : " + age);
            }

        }

        static void Main(string[] args)
        {
            // 구조체는 선언하며 바로 변수가 됐지만,
            // 클래스는 객체화(new)를 진행하고 변수에 연결해야만 사용 할 수 있다.
            Person p1 = new Person(); // 이때 생성자가 실행되며, 해당 생성자(오버로딩)을 실행
            Person p2 = new Person("John", 25);

            p2.PrintInfo();

        }
    }
}
