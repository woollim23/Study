#pragma once
#include <assert.h>
/*-----클래스 버전 가변 배열-----*/

template<typename T> // 클래스 템플릿으로 변환
class CArr
{
private:
	T* m_pData; // 저장할 데이터 T로 변환
	int m_iCount;
	int m_iMaxCount;

public:
	void Push_Back(const T& _Data); // 원형을 그대로 받기 위함, 주소 변경을 보호
	void Resize(int _iResizeCount); // 재할당 함수, 공간 칸수를 받음
	
	T& operator[] (int idx); // 배열처럼 쓸 수 있도록, 인덱스 받는 함수

public:
	CArr();
	~CArr();
};

/*-------- 초기화 함수 ---------*/
// 선언한 멤버순으로 초기화 하는게 성능적으로 좋을 수도 있음
template<typename T>
CArr<T>::CArr()
	:m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	// new 동적할때 쓰는 키워드, int * 2만큼 공간 할당
	m_pData = new T[2];

}

/*-------- 메모리 해제 함수 ---------*/
template<typename T>
CArr<T>::~CArr()
{
	// free와 같은 주소해제
	// 여러개 선언했을때는 []도 같이, 단일일 때는 제외
	delete[] m_pData;
}

/*-------- 데이터 추가 함수 ---------*/
template<typename T>
void CArr<T>::Push_Back(const T& _Data)
{
	// 힙 영역에 할당한 공간을 다 채웠는지 확인
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// 재할당
		Resize(this->m_iMaxCount * 2);
	}

	// 데이터 추가
	this->m_pData[this->m_iCount++] = _Data;
}

/*-------- 재할당 함수 ---------*/
template<typename T>
void CArr<T>::Resize(int _iResizeCount)
{
	// 현재 최대 수용량보다 더 적은 수치로 확장하려는 경우
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // 에러 검출용 코드
	}
	// 1. 리사이즈 시킬 개수만큼 동적할당 함
	T* pNew = new T[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pData;

	// 4. 배열이 새로 할당한 공간을 가리키게 힘
	m_pData = pNew;

	// 5. MaxCount 변경점 적용(2배)
	m_iMaxCount = _iResizeCount;
}

/*-------- 인덱스 함수 ---------*/
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}