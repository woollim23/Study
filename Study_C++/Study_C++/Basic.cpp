#include <iostream>
using namespace std;

int main()
{
	// 포인터 변수 증감연산자 테스트
	int num[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* inum = num;
	cout << *inum << " ";

	inum++;

	cout << *inum;

	return 0;
}