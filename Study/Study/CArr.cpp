#include "CArr.h"
#include <assert.h>

/*-------- �ʱ�ȭ �Լ� ---------*/
// ������ ��������� �ʱ�ȭ �ϴ°� ���������� ���� ���� ����
CArr::CArr()
	:m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2) 
{
	// new �����Ҷ� ���� Ű����, int * 2��ŭ ���� �Ҵ�
	m_pInt = new int[2];

}

/*-------- �޸� ���� �Լ� ---------*/
CArr::~CArr()
{
	// free�� ���� �ּ�����
	// ������ ������������ []�� ����, ������ ���� ����
	delete[] m_pInt;
}

/*-------- ������ �߰� �Լ� ---------*/
void CArr::Push_Back(int _Data)
{
	// �� ������ �Ҵ��� ������ �� ä������ Ȯ��
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// ���Ҵ�
		Resize(this->m_iMaxCount * 2);
	}

	// ������ �߰�
	this->m_pInt[this->m_iCount++] = _Data;
}

/*-------- ���Ҵ� �Լ� ---------*/
void CArr::Resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // ���� ����� �ڵ�
	}
	// 1. �������� ��ų ������ŭ �����Ҵ� ��
	int* pNew = new int[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� ����
	for (int i = 0; i < m_iCount; i++)
	{
		pNew[i] = m_pInt[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] m_pInt;

	// 4. �迭�� ���� �Ҵ��� ������ ����Ű�� ��
	m_pInt = pNew;

	// 5. MaxCount ������ ����(2��)
	m_iMaxCount = _iResizeCount;
}

/*-------- �ε��� �Լ� ---------*/
int& CArr::operator[](int idx)
{
	return m_pInt[idx];
}
