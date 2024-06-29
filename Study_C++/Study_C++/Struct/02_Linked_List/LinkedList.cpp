#include <iostream>

#include "LinkedList.h"
// 추가할 기능 - tailnode, frontnode


/*------ 연결 리스트 초기화 ------*/
void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

/*------ 데이터 추가 함수(리스트 맨 뒤에) ------*/
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
		_pList->pHeadNode = pNode; // 최초의 노드이므로 헤드노드에 저장
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서 반복, 넥스트노드가 null이면 종료
		// 해당 노드의 pNext 를 생성시킨 노드의 주소로 채움
		tNode* pCurFinalNode = _pList->pHeadNode; // 시작은 헤드노드부터
		while (pCurFinalNode->pNextNode) // 현재 가리키고 있는 노드의 넥스트 노드가 없으면(null) 종료
		{
			pCurFinalNode = pCurFinalNode->pNextNode; // 다음노드 주소 부여(반복)
		}
		pCurFinalNode->pNextNode = pNode; // 리스트에 저장된 마지막 노드의 넥스트노드 주소에 저장
	}

	_pList->iCount++; // 갯수증가
}

/*------ 데이터 추가 함수(리스트 맨 앞에) ------*/
void PushFront(tLinkedList* _pList, int _iData)
{
	// 데이터를 저장할 노드 생성
	// 데이터 복사
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;

	pNode->pNextNode = _pList->pHeadNode; // 헤드노드를 현 노드의 넥스트 노드로 받음
	_pList->pHeadNode = pNode; // 리스트의 헤드노드에는 현노드 저장

	_pList->iCount++; // 갯수증가
}


/*------ 메모리 해제 함수 ------*/
void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeletNode = _pList->pHeadNode;

	while (pDeletNode) // 마지막 노드일때 까지 반복
	{
		tNode* pNext = pDeletNode->pNextNode; // 다음 노드대입
		free(pDeletNode);// 현재 노드는 삭제
		pDeletNode = pNext; // 다음노드를 현재 노드로 변경
	}

	_pList->iCount = 0;
}
