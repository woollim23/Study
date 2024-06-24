/*----가변배열----*/

#include <iostream>
#include <time.h>

#include "Arr.h"
using namespace std;

void BubbleSort(int* _pData, int _iCount)
{
	// 데이터가 1개 이하면 정렬하지 않음
	if (_iCount <= 1)
		return;

	while (true)
	{
		bool bFinish = true;

		// 오름차순 정렬
		for (int i = 0; i < (_iCount - 1); i++)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}

		if (bFinish) // 버블정렬 종료
			break;
	}
}

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

	Sort(&s, BubbleSort); // 함수는 이름자체가 주소, & 생략가능

	for (int i = 0; i < s.iCount; i++)
	{
		cout << s.pInt[i] << " ";
	}

	ReleaseArr(&s);

	return 0;
}