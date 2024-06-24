#pragma once
/*--------- 클래스 템플릿 리스트 ---------*/

/*--------- 노드 구조체 템플릿 ---------*/
template<typename T>
struct tListNode // c++ 에서는 구조체나 클래스나 비슷함
{
	T data;
	tListNode<T>* pPrev;
	tListNode<T>* pNext; // 내부에서 선언하여 <T> 생략가능

	// 구조체 기본 생성자(들어오는 인자 X)
	tListNode()
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}

	// 구조체 생성자(들어오는 인자 o)
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}
};

/*--------- 리스트 클래스 ---------*/
template<typename T>
class CList
{
public:
	// 외부에 있기 떄문에 <T>가 꼭 붙어야함
	tListNode<T>* m_pHead;
	tListNode<T>* m_pTail;
	int m_iCount;

public:
	void push_back(const T& _data);  // T가 미정이기 때문에 복사비용을 줄이기 위해 레퍼런스로 받아옴
	void push_front(const T& _data); // 원본 수정을 방지하기 위해 const 키워드를 붙임

public:
	CList();
	~CList();
};


/*--------- 데이터 입력 함수(맨뒤) ---------*/
template<typename T>
void CList<T>::push_back(const T& _data)
{
	// 입력된 데이터를 저장할 노드를 동적할당 함
	// 생성자를 통해 인자를 전달하여 초기화 함(간결)
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	if (nullptr == m_pHead)
	{
		// 처음 입력된 데이터라면
		m_pHead = pNewNode; // 방금 생성시킨 노드를 헤드가 가리키게 함
		m_pTail = pNewNode; // 첫 노드는 헤드와 테일이 같음 
	}
	else
	{
		// 데이터가 1개 이상에서 입력된 경우
		// 현재 가장 마지막 데이터(tail)를 저장하고 있는 노드가
		// 새로 생성된 노드와 서로 가리키게 함

		// 현재 기준 가장 마지막 노드의 넥스트 주소에 방금 생성한 노드를 가리키게 함 
		m_pTail->pNext = pNewNode;

		// 방금 생성한 노드의 앞 노드 주소에 현재 기준 가장 마지막 노드를 가리키게 함
		pNewNode->pPrev = m_pTail;

		// 이제 List의 가장 마지막 노드는 방금 생성한 노드
		m_pTail = pNewNode;

	}
	// 데이터 갯수 증가
	m_iCount++;
}


/*--------- 데이터 입력 함수(맨앞) ---------*/
template<typename T>
void CList<T>::push_front(const T& _data)
{
	// 원래 리스트가 알고 있던 헤드주소를 지금 생성하는 노드의 넥스트노드로 입력
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

	// 원래 헤드노드의 이전 노드 주솟값에 방금 생성한 노드를 입력하여, 서로 가리키게 함
	m_pHead->pPrev = pNewNode;

	// 방금 생성된 노드를 새로운 헤드주소로 갱신
	m_pHead = pNewNode;

	// 데이터 갯수 증가
	m_iCount++;
}


/*--------- 생성자 ---------*/
template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{
}


/*--------- 소멸자 ---------*/
template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead;

	while (pDeleteNode)
	{
		tListNode<T>* pNext = pDeleteNode->pNext;
		delete(pDeleteNode);
		pDeleteNode = pNext;
	}
}