#pragma once

typedef struct _tagNode
{
	int iData;
	tNode* pNextNode;
}tNode;

typedef struct _tagList
{
	tNode* pHeadNode;
	int iCount;
}tLinkedList;

//