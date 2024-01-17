#pragma once

// 개별 노드
typedef struct _tagNode
{
	int iData;
	struct _tagNode* pNextNode;
}tNode;

// 연결 리스트 
typedef struct _tagList 
{
	tNode* pHeadNode; // 최초의 노드 주소 저장
	int iCount; // 노드갯수
}tLinkedList;

// 연결 리스트 초기화
void InitList(tLinkedList* _pList);

// 데이터 추가 함수(리스트 맨 뒤에)
void PushBack(tLinkedList* _pList, int _iData);

// 데이터 추가 함수(리스트 맨 앞에)
void PushFront(tLinkedList* _pList, int _iData);

// 메모리 해제 함수
void ReleaseList(tLinkedList* _pList);