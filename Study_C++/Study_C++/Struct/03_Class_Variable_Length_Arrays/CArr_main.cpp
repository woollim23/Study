#include <iostream>

#include "CArr.h"
using namespace std;

int main()
{
	CArr<int> myvector;

	myvector.Push_Back(1);
	myvector.Push_Back(2);
	myvector.Push_Back(3);

	CArr<int>::iterator myiter = myvector.begin();

	for (; myiter != myvector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}

	myiter = myvector.begin();

	myiter++;
	myiter++;

	cout << *(myiter--) << " ";

	cout << *(--myiter) << " ";

	return 0;
}