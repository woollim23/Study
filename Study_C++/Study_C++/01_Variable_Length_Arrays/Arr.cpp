#include "Arr.h"
#include <iostream>

/*------배열 초기화 함수------*/
void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2); // ? new 버전이면 어떨까 / 템플릿으로 바꿔보기
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

/*------공간 추가 확장------*/
void Reallocate(tArr* _pArr)
{
	// 1. 2배 더 큰 공간을 동적할당 함
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int)); // ? new 버전이면 어떨까 / 템플릿으로 바꿔보기

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사
	for (int i = 0; i < _pArr->iCount; i++)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존 공간은 메모리 해제
	free(_pArr->pInt);

	// 4. 배열이 새로 할당한 공간을 가리키게 힘
	_pArr->pInt = pNew;

	// 5. MaxCount 변경점 적용(2배)
	_pArr->iMaxCount *= 2;
}// main에선 못사용 - 헤더파일에 없애서 숨김

/*------데이터 추가 함수------*/
void PushBack(tArr* _pArr, int _iData)
{
	// 힙 영역에 할당한 공간을 다 채웠는지 확인
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// 재할당
		Reallocate(_pArr);
	}

	// 데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData;

}

/*------배열 메모리 해제 함수------*/
void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Sort(tArr* _pArr, void(*SortFunc)(int*, int))
{
	SortFunc(_pArr->pInt, _pArr->iCount);
}