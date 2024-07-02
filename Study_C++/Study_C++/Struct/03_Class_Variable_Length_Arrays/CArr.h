#pragma once
#include <assert.h>
/*-----클래스 버전 가변 배열(vector)-----*/

template<typename T> // 클래스 템플릿으로 변환
class CArr
{
private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	void Push_Back(const T& _Data); // 원형을 그대로 받기 위함, 주소 변경을 보호
	void Resize(int _iResizeCount); // 재할당 함수, 공간 칸수를 받음
	T* data() { return m_pData; } // 데이터의 시작 주소 반환
	int size() { return m_iCount; } // 현재 저장 데이터 갯수
	int capacity() { return m_iMaxCount; } // 최대 데이터 갯수
	T& operator[] (int idx); // 배열처럼 쓸 수 있도록, 인덱스 받는 함수

	class iterator; // 반복자 함수 전방선언
	iterator begin(); // 시작을 가리키는 iterator 를 만들어서 반환해줌
	iterator end();
	iterator erase(const iterator& _iter);

public:
	CArr();
	~CArr();

	// 반복자(iterator)란 가변배열이 관리하는 데이터 요소를 가리키는 역할
	// 이너클래스로 반복자 구현해보기
	// CArr의 프라이빗 변수도 접근 가능 -> inner 클래스를 포함하고 있는 클래스의 private 멤버에 접근 가능
	// 템플릿 적용 됨
	class iterator
	{
	private:
		CArr* m_pArr; // iterator 가 가리킨 데이터를 관리하는 가변배열 주소
		T* m_pData; // 데이터들의 시작 주소
		int m_iIdx; // 가리키는 데이터의 인덱스

	public:
		// 참조값을 돌려줌
		T& operator * ()
		{
			// 가변배열이 알고 있는 주소와, iterator 가 알고있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			// iterator 가 end iterator 인 경우
			if ((m_pArr->m_pData != m_pData) || (-1 == m_iIdx))
				assert(nullptr);

			return m_pData[m_iIdx];
		}

		// ++ 전위 증가연산자 구현
		// 중복 연산을 위해 반환값을 자기 자신으로
		iterator& operator ++()
		{
			// end iterator 인 경우
			// 데이터가 재할당 되어 주소값이 변경된 경우
			if ((m_pArr->m_pData != m_pData) || (-1 == m_iIdx))
				assert(nullptr); // 오류 상황

			// iterator 가 마지막 데이터를 가리키고 있는 경우
			// --> end iterator가 된다.
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		// ++ 후위 증가연산자 구현
		// 반환형에 레퍼런스를 안줌. 원본 참조를 리턴하는 것이 아닌 또다른 복사본을 리턴하게 되는 것
		iterator operator ++(int)
		{
			// 복사 생성자를 이용하여 원본 이터레이터가 지역 이터레이터로 복사됨
			iterator copy_iter = *this;

			// 위에서 구현한 전위연산자 활용
			++(*this);

			// 복사본을 리턴하여 증가이전 값을 반환
			return copy_iter;
		}

		// -- 전위, 후위 직접 구현해보기
		// 전위
		iterator& operator --()
		{
			// begin iterator 인 경우
			// 데이터가 재할당 되어 주소값이 변경된 경우
			// 저장된 데이터가 없는 경우
			if ((this->m_iIdx == 0) || (m_pArr->m_pData != m_pData) || (m_pArr->size() == 0))
				assert(nullptr); // 오류 상황
			else
			{
				--m_iIdx;
			}

			return *this;
		}

		iterator operator --(int)
		{
			// 복사 생성자를 이용하여 원본 이터레이터가 지역 이터레이터로 복사됨
			iterator copy_iter = *this;

			// 위에서 구현한 전위연산자 활용
			--(*this);

			// 복사본을 리턴하여 증가이전 값을 반환
			return copy_iter;
		}

		// 비교연산자
		bool operator == (const iterator& _otheriter)
		{
			// 데이터 주소와 인덱스 모두 일치해야 함
			if ((m_pData == _otheriter.m_pData) && (m_iIdx == _otheriter.m_iIdx))
			{
				return true;
			}
			
			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			/*
			if ((m_pData == _otheriter.m_pData) && (m_iIdx == _otheriter.m_iIdx))
			{
				return false;
			}

			return true;
			*/

			return !(*this == _otheriter);
		}
		
	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1) // 시작이자 end인 상태 (데이터가 비어있는 상태)
		{}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
		{}

		~iterator()
		{}
	};
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

// 시작을 가리키는 iterator 를 만들어서 반환해줌
// 타입네임 적은 이유 -> 특정 타입이란 것을 알리기 위해
template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	/* 생성자로 만들게 되면서 생략됨
	iterator iter;
	// 만들어진 반복자가 본인이 관리할 데이터의 시작 주소와 똑같이 함
	iter.m_pData = this->m_pData;
	// 시작을 가리키므로 0
	iter.m_iIdx = 0;

	return iter;
	*/

	// 데이터가 없을때의 반환, begin() == end()
	if (0 == m_iCount)
		return iterator(this, m_pData, -1);

	// 변수명 부여할 필요도 없이 임시 객체 만드는 즉시 반환
	return iterator(this, m_pData, 0);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// 데이터 마지막 항목의 다음 것, 비어있음
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(const iterator& _iter)
{
	return iterator();
}
