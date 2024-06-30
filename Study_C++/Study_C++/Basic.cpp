#include <iostream>
using namespace std;

class parent
{
protected :
	int iP;
};

class child : public parent
{

};

class childchild : public child
{
public:
	void test()
	{
		iP = 9;
		cout << iP;
	}
};

int main()
{
	// 포인터 변수 증감연산자 테스트
	int num[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* inum = num;
	cout << *inum << " ";

	inum++;

	cout << *inum << endl;

	childchild cc;
	cc.test();

	return 0;
}