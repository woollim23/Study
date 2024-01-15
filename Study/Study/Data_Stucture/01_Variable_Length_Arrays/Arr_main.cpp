/*----�����迭----*/
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
		int iRand = rand() % 100 + 1; // 1 ~ 100 ���� ��������
		PushBack(&s, iRand);
	}

	Sort(&s); // �������� ����

	for (int i = 0; i < s.iCount; i++)
	{
		cout << s.pInt[i] << " ";
	}

	ReleaseArr(&s);

	return 0;
}