/*----연결형리스트----*/
#include <iostream>

#include "LinkedList.h"
using namespace std;

int main()
{
	tLinkedList list = {};
	InitList(&list);

	PushBack(&list, 100);
	PushBack(&list, 200);
	PushFront(&list, 300);

	tNode* pNode = list.pHeadNode;
	for (int i = 0; i < list.iCount; i++)
	{
		cout << pNode->iData << " ";
		pNode = pNode->pNextNode;
	}

	ReleaseList(&list);

	return 0;
}