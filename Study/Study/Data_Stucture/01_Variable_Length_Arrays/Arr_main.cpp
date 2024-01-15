/*----가변배열----*/
#include <iostream>
#include <time.h>

#include "Arr.h"
using namespace std;

int main()
{
	tArr s = {};
	InitArr(&s);

	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		int iRand = rand() % 100 + 1; // 1 ~ 100 값을 랜덤으로
		PushBack(&s, iRand);
	}

	Sort(&s); // 버블정렬 실행

	for (int i = 0; i < s.iCount; i++)
	{
		cout << s.pInt[i] << " ";
	}

	ReleaseArr(&s);

	return 0;
}