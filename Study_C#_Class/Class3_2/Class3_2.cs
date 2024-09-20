using System;
using System.Collections.Generic;

namespace Class3_2
{
    internal class Class3_2
    {
        // ----------------1. 상속 관련----------------
        // 부모 클래스
        public class Animal
        {
            public string Name { get; set; }
            public int Age { get; set; }

            public void Eat()
            {
                Console.WriteLine("Animal is eating.");
            }

            public void Sleep()
            {
                Console.WriteLine("Animal is sleeping.");
            }
        }

        // 자식 클래스
        public class Dog : Animal
        {
            public void Bark()
            {
                Console.WriteLine("Dog is bark.");
            }

            public void Eat()
            {
                Console.WriteLine("Dog is eating.");
            }
        }

        public class Cat : Animal
        {
            public void Meow()
            {
                Console.WriteLine("Cat is meow.");

            }
            public void Eat()
            {
                Console.WriteLine("Cat is eating.");
            }
        }

        // ----------------2. 가상함수 관련----------------
        public class Unit
        {
            public virtual void Move() // 가상함수 : 자식이 재정의 했을 수 있다. 자식의 함수 주소를 테이블에 저장한다. 함수 구동전에 테이블 먼저 확인
            {
                Console.WriteLine("두발로 걷기");
            }

            public void Attack()
            {
                Console.WriteLine("Unit 공격");
            }
        }

        public class Marine : Unit { }

        public class Zergling : Unit
        {
            public void Attack()
            {
                Console.WriteLine("Zergling 공격");
            }
            public override void Move() // 가상함수 생성을 위해 "override"를 붙인다
            {
                Console.WriteLine("네발로 걷기");
            }
        }

        // ----------------3. 추상클래스 관련----------------
        abstract class Shape
        {
            public abstract void Draw();
            // 이 클래스를 상속한 자식들은 모두 Draw 클래스를 정의하도록 강제성이 부여됨
        }

        class Circle : Shape
        {
            public override void Draw() // 추상 함수를 재정의 하는 함수는 "override" 를 붙임
            {
                Console.WriteLine("Drawing a Circle");
            }
        }

        class Square : Shape
        {
            public override void Draw()
            {
                Console.WriteLine("Drawing a Square");
            }
        }

        class Triangle : Shape
        {
            public override void Draw()
            {
                Console.WriteLine("Drawing a Triangle");
            }
        }

        static void Main(string[] args)
        {
            // ----------------1. 상속 관련----------------
            Dog dog = new Dog(); // 동적할당
            dog.Name = "Bobby";
            dog.Age = 3;

            dog.Eat(); // 자식 클래스 안에 있는 것으로 오버라이딩
            dog.Sleep();
            dog.Bark();

            Console.WriteLine();

            // ----------------2. 가상함수 관련----------------
            //Marine marine = new Marine();
            //marine.Move();
            //marine.Attack();

            Zergling zergling = new Zergling();
            zergling.Move(); // 자식 클래스 안에 있는 것으로 오버라이딩
            zergling.Attack(); // 자식 클래스 안에 있는 것으로 오버라이딩

            Console.WriteLine();

            // Unit으로 관리하자
            // Unit은 참조의 형태, 마린과 저글링은 실형태
            List<Unit> list = new List<Unit>();
            list.Add(new Marine());
            list.Add(new Zergling());

            // 자식클래스로 접근했을 때와는 다르게 부모 클래스로 접근하면
            // 메모리 구조상 부모클래스 내부의 멤버 함수와 더 가깝기 때문에 오버라이딩이 되지 않는다.
            foreach(Unit unit in list)
            {
                unit.Attack();
                unit.Move();
            }
            Console.WriteLine();

            // ----------------2. 가상함수 관련----------------
            List<Shape> list2 = new List<Shape>();
            list2.Add(new Circle());
            list2.Add(new Square());
            list2.Add(new Triangle());

            foreach(Shape shape in list2)
            {
                shape.Draw();
            }
            

        }
    }
}
