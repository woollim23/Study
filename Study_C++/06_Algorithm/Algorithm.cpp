#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{
	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	// ������ ���� �Լ�
	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			// ���� �۾�
			int newCapacity = static_cast<int>(_capacity * 1.5);
			// _capacity�� 0�̳� 1�� ��� üũ
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// ������ ����
		_data[_size] = value;
		// ������ ���� ����
		_size++;
	}

	// ���� ���� ���� �Լ�
	void reserve(int capacity)
	{
		if (_capacity >= capacity)
		{
			return;
		}

		_capacity = capacity;

		T* newData = new T[_capacity];

		// ������ ����
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data)
			delete[] _data;

		// ��ü
		_data = newData;

	}

	T& operator[](const int pos) { return _data[pos]; }
	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}
		 
		_size = 0;
	}

private:
	T* _data = nullptr;
	int _size = 0;
	int _capacity = 0;
};

template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}

	Node(const T& value) : _prev(nullptr), _next(nulltpr), _data(value)
	{

	}

private:
	Node*	 _prev;
	Node*	 _next;
	T		 _data;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{

	}

	void pop_back()
	{

	}

private:
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}

public:
	Node<T>*	_head;
	Node<T>*	_tail;
	int			_size;

};
int main()
{
	/* ------------- ���� ---------------
	vector<int> v;

	// resize�� ����, capacity�� ���� 10���� ����
	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;
	// capacity �� ����
	v.reserve(100);
	cout << v.size() << " " << v.capacity() << endl;

	for (int i = 0; i < 200; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;

	v.clear();

	cout << v.size() << " " << v.capacity() << endl;

	*/


	list<int> li;
	
	list<int>::iterator eraselt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraselt = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}
	// ����Ʈ�� []�� �̿��� ���� ������ �Ұ���

	li.pop_back();

	li.erase(eraselt);

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}



} 