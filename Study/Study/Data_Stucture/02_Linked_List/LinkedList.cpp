#include <iostream>

#include "LinkedList.h"

// �߰��� ��� - tailnode, frontnode

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// �����͸� ������ ��� ����
	// ������ ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// �߰��� �����Ͱ� ó������ �ƴ��� Ȯ��
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// ���� ���� ������ ��带 ã�Ƽ�,
		// �ش� ����� pNext �� ������Ų ����� �ּҷ� ä��
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (pCurFinalNode->pNextNode) // ���� ����Ű�� �ִ� ����� �ؽ�Ʈ ��尡 ������(null) ����
		{
			pCurFinalNode = pCurFinalNode->pNextNode;
		}
		pCurFinalNode->pNextNode = pNode;
	}

	_pList->iCount++; // ��������
}

void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeletNode = _pList->pHeadNode;

	while (pDeletNode) // ������ ����϶� ���� �ݺ�
	{
		tNode* pNext = pDeletNode->pNextNode; // ���� ������
		free(pDeletNode);
		pDeletNode = pNext;
	}
}
