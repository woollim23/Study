#pragma once
#include <assert.h>
/*-----Ŭ���� ���� ���� �迭-----*/

template<typename T> // Ŭ���� ���ø����� ��ȯ
class CArr
{
private:
	T* m_pData; // ������ ������ T�� ��ȯ
	int m_iCount;
	int m_iMaxCount;

public:
	void Push_Back(const T& _Data); // ������ �״�� �ޱ� ����, �ּ� ������ ��ȣ
	void Resize(int _iResizeCount); // ���Ҵ� �Լ�, ���� ĭ���� ����
	
	T& operator[] (int idx); // �迭ó�� �� �� �ֵ���, �ε��� �޴� �Լ�

public:
	CArr();
	~CArr();
};

/*-------- �ʱ�ȭ �Լ� ---------*/
// ������ ��������� �ʱ�ȭ �ϴ°� ���������� ���� ���� ����
template<typename T>
CArr<T>::CArr()
	:m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	// new �����Ҷ� ���� Ű����, int * 2��ŭ ���� �Ҵ�
	m_pData = new T[2];

}

/*-------- �޸� ���� �Լ� ---------*/
template<typename T>
CArr<T>::~CArr()
{
	// free�� ���� �ּ�����
	// ������ ������������ []�� ����, ������ ���� ����
	delete[] m_pData;
}

/*-------- ������ �߰� �Լ� ---------*/
template<typename T>
void CArr<T>::Push_Back(const T& _Data)
{
	// �� ������ �Ҵ��� ������ �� ä������ Ȯ��
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// ���Ҵ�
		Resize(this->m_iMaxCount * 2);
	}

	// ������ �߰�
	this->m_pData[this->m_iCount++] = _Data;
}

/*-------- ���Ҵ� �Լ� ---------*/
template<typename T>
void CArr<T>::Resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // ���� ����� �ڵ�
	}
	// 1. �������� ��ų ������ŭ �����Ҵ� ��
	T* pNew = new T[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� ����
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] m_pData;

	// 4. �迭�� ���� �Ҵ��� ������ ����Ű�� ��
	m_pData = pNew;

	// 5. MaxCount ������ ����(2��)
	m_iMaxCount = _iResizeCount;
}

/*-------- �ε��� �Լ� ---------*/
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}