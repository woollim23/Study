#pragma once

typedef struct _tagNode
{
	int iData;
	struct _tagNode* pNextNode;
}tNode;

typedef struct _tagList
{
	tNode* pHeadNode;
	int iCount;
}tLinkedList;

// ������ ����Ʈ �ʱ�ȭ
void InitList(tLinkedList* _pList);

// ������ ����Ʈ ������ �߰� �Լ�
void PushBack(tLinkedList* _pList, int _iData);

// ������ ����Ʈ �޸� ���� �Լ�
void ReleaseList(tLinkedList* _pList);