#include "CArr.h"
#include <assert.h>

/*-------- 초기화 함수 ---------*/
// 선언한 멤버순으로 초기화 하는게 성능적으로 좋을 수도 있음
CArr::CArr()
	:m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2) 
{
	// new 동적할때 쓰는 키워드, int * 2만큼 공간 할당
	m_pInt = new int[2];

}

/*-------- 메모리 해제 함수 ---------*/
CArr::~CArr()
{
	// free와 같은 주소해제
	// 여러개 선언했을때는 []도 같이, 단일일 때는 제외
	delete[] m_pInt;
}

/*-------- 데이터 추가 함수 ---------*/
void CArr::Push_Back(int _Data)
{
	// 힙 영역에 할당한 공간을 다 채웠는지 확인
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// 재할당
		Resize(this->m_iMaxCount * 2);
	}

	// 데이터 추가
	this->m_pInt[this->m_iCount++] = _Data;
}

/*-------- 재할당 함수 ---------*/
void CArr::Resize(int _iResizeCount)
{
	// 현재 최대 수용량보다 더 적은 수치로 확장하려는 경우
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // 에러 검출용 코드
	}
	// 1. 리사이즈 시킬 개수만큼 동적할당 함
	int* pNew = new int[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pInt[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pInt;

	// 4. 배열이 새로 할당한 공간을 가리키게 힘
	m_pInt = pNew;

	// 5. MaxCount 변경점 적용(2배)
	m_iMaxCount = _iResizeCount;
}

/*-------- 인덱스 함수 ---------*/
int& CArr::operator[](int idx)
{
	return m_pInt[idx];
}
