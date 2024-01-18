/*---- 클래스 템플릿 리스트 ----*/
#include <iostream>

#include "CList.h"
using namespace std;

int main()
{
	CList<int> list;
	for (int i = 0; i < 4; i++)
	{
		list.push_back(i);
	}

	tListNode<int>*  pNode = list.m_pHead;
	for (int i = 0; i < 4; i++)
	{
		cout << pNode->data << " ";
		pNode = pNode->pNext;
	}

	
	return 0;
}