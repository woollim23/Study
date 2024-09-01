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

	// 데이터 삽입 함수
	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			// _capacity가 0이나 1일 경우 체크
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = value;
		// 데이터 개수 증가
		_size++;
	}

	// 저장 공간 증설 함수
	void reserve(int capacity)
	{
		if (_capacity >= capacity)
		{
			return;
		}

		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data)
			delete[] _data;

		// 교체
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

	Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}

public:
	Node*	 _prev;
	Node*	 _next;
	T		 _data;
};

// 이터레이터
template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{
	
	}

	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	// it++
	Iterator& operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	// it--
	Iterator& operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->_data;
	}

	// 같은지 체크
	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}
	// 다른지 체크
	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	List() : _size(0)
	{
		// 더미 헤드, 테일 생성
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_next = _tail;
		_tail->_prev = _head;
	}

	~List()
	{
		while (_size > 0)
			pop_back();

		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}

	void pop_back()
	{
		RemoveNode(_tail->_prev);
	}

private:
	// 내부에서 인서트 관리하는 함수
	// [head] <-> [1] <-> [prevNode] <-> [before] <-> [tail]
	// [head] <-> [1] <-> [prevNode] <-> "[newNode]" <-> [before] <-> [tail]
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		// 이전 노드의 다음 노드에 새로운 노드를 연결
		prevNode->_next = newNode;
		// 새로운 노드의 앞은 당연히 이전 노드
		newNode->_prev = prevNode;

		// 새 노드의 다음을
		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}
	
	// 특정 노드 데이터 삭제하는 함수
	// [head] <-> [prevNode] <-> "[node]" <-> [nextNode] <-> [tail]
	// [head] <-> [prevNode] <-> [nextNode] <-> [tail]
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	// 사이즈 반환 함수
	int size() { return _size; }

public:
	using iterator = Iterator<T>;
	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	// it '앞에' 추가
	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

public:
	Node<T>*	_head;
	Node<T>*	_tail;
	int			_size;

};
int main()
{
	/* ------------- 벡터 ---------------
	vector<int> v;

	// resize를 조정, capacity도 같이 10으로 증가
	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;
	// capacity 만 조정
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


	List<int> li;

	List<int>::iterator eraseIt;
	// [ ] <-> [ ] <-> [ ] <-> [ ]  <-> [ ]  <-> [ ]
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back();

	li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}



} 