/*----가변배열----*/
#include "Arr.h"
#include <iostream>
using namespace std;

int main()
{
	tArr s = {};
	InitArr(&s);

	for (int i = 0; i < 10; i++)
	{
		PushBack(&s, i);
	}

	for (int i = 0; i < s.iCount; i++)
	{
		cout << s.pInt[i] << " ";
	}

	ReleaseArr(&s);

	return 0;
}