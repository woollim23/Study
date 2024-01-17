#include <iostream>

#include "CArr.h"
using namespace std;

int main()
{
	CArr carr;
	carr.Push_Back(10);
	carr.Push_Back(20);
	carr.Push_Back(30);

	cout << carr[2];
	
	return 0;
}