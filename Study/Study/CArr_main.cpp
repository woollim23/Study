#include <iostream>

#include "CArr.h"
using namespace std;

int main()
{
	CArr<float> carr;
	carr.Push_Back(10.1);
	carr.Push_Back(20.23);
	carr.Push_Back(30.6);

	cout << carr[2];
	
	return 0;
}