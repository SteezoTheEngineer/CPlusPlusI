#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string.h>
#include <array>


using namespace std;


// Class for stack
template <class T, int _size>
class stack
{
private:
	array<T, _size> arr;
	int m_top = -1;
	int capacity = _size;

public:
	// constructor
	stack(){}
	// destructor
	~stack(){}

	void push(T x)
	{
	if (isFull())
	{
		cout << "StackOverFlow\n";
	}

	cout << "Inserting " << x << endl;
	arr[++m_top] = x;
	}

	T pop()
	{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\n";
	}

	cout << "Removing " << peek() << endl;

	// decrease stack size by 1 and return the popped element
	return arr[m_top--];
	}

	T peek()
	{
		return arr[m_top];

	}

	int size()
	{
		return m_top + 1;
	}

	void print()
	{
		cout<< "Elements in the Stack \n";
		for (int i = 0; i < m_top+1; i++) {
  		cout << arr[i] << "\n";
		}
	}

	bool isEmpty()
	{
		return m_top == -1;	// or return size() == 0;
	}

	bool isFull()
	{
		return m_top == capacity - 1;	// or return size() == capacity;
	}
};


#endif //STACK_H