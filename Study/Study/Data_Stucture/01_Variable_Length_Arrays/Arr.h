#pragma once
// - 가변배열을 공간을 계속 미리 확보하고 데이터를 받음

typedef struct _tabArr
{
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;

// 배열 초기화 함수
void InitArr(tArr* _pArr);

// 데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);

// 배열 메모리 해제 함수
void ReleaseArr(tArr* _pArr);

// 정렬, 변수로 함수를 받음
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));