#include <iostream>

#include "LinkedList.h"

// 추가할 기능 - tailnode, frontnode

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// 데이터를 저장할 노드 생성
	// 데이터 복사
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 추가한 데이터가 처음인지 아닌지 확인
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서,
		// 해당 노드의 pNext 를 생성시킨 노드의 주소로 채움
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (pCurFinalNode->pNextNode) // 현재 가리키고 있는 노드의 넥스트 노드가 없으면(null) 종료
		{
			pCurFinalNode = pCurFinalNode->pNextNode;
		}
		pCurFinalNode->pNextNode = pNode;
	}

	_pList->iCount++; // 갯수증가
}

void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeletNode = _pList->pHeadNode;

	while (pDeletNode) // 마지막 노드일때 까지 반복
	{
		tNode* pNext = pDeletNode->pNextNode; // 다음 노드대입
		free(pDeletNode);
		pDeletNode = pNext;
	}
}
