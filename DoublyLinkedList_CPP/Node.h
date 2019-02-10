#pragma once
#include <memory>

using namespace std;

template <typename T>
class Node
{
public:
	T Value;
	shared_ptr<Node<T>> Next;
	shared_ptr<Node<T>> Prev;

	
	//constructor
	Node(T value)
	{
		Value = value;
	}
};

