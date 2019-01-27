#pragma once
#include <memory>

using namespace std;

template <typename T>
class Node
{
public:
	T Value;
	unique_ptr<Node<T>> Next;
	Node<T>* Prev;
	
	//constructor
	Node(T value)
	{
		Value = value;
	}

private:

};

