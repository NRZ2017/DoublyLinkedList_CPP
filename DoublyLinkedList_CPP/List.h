#pragma once
#include <memory>
#include "Node.h"

using namespace std;

template <typename T>
class List
{

public:
	Node<T>* Head;

	List()
	{
		Head == nullptr;
	}

	void AddLast(T value)
	{

		if (Head == nullptr)
		{
			Head = new Node<T>(value);
			Head->Next.reset(Head);
			Head->Prev = Head;
			return;
		}

		Node<T>* tail = Head->Prev;
		Node<T>* add = new Node<T>(value);
		add->Next = move(Head->Prev->Next);
		tail->Next.reset(add);
		Head->Prev = add;
		add->Prev = tail;
	}

	void AddFirst(T value)
	{
		if (Head == nullptr)
		{
			Head = new Node<T>(value);
			Head->Next.reset(Head);
			Head->Prev = Head;
			return;
		}

		Node<T>* temp = new Node<T>(value);
		temp->Next = Head;
		Head = temp;
	}

	bool RemoveAt(int index)
	{
		if (Head == nullptr)
		{
			return false;
		}

		Node<T>* tempNode = Head;
		Node<T>* prevNode = nullptr;
		for (int i = 0; i < index; i++)
		{
			prevNode = tempNode;
			tempNode = tempNode->Next;
		}
		prevNode->Next = tempNode->Next;
		if (tempNode->Next == nullptr)
		{
			Head->Prev = prevNode->Next;
		}

		return true;
	}

	bool RempveFront()
	{
		if (Head == nullptr)
		{
			return false;
		}

		Head = Head->Next;
		Head->Prev = nullptr;
		return true;
	}

	bool RemoveEnd()
	{
		if (Head == nullptr)
		{
			return false;
		}

		Node<T>* Tail = Head->Prev;
		Tail->Prev->Next = nullptr;
		Tail = Tail->Prev;
		return true;
	}

	void AddAt(int position, T value)
	{
		Node<T>* temp = Head;
		if (temp == nullptr)
		{
			Head = new Node<T>(value);
			Head->Next.reset(Head);
			Head->Prev = Head;
			return;
		}

		for (int i = 0; i < position; i++)
		{
			temp = temp->Next;
			if (temp == nullptr)
			{
			}
		}

		Node<T>* add = new Node<T>*(value);
		if (temp->Prev != nullptr)
		{
			add->Prev = temp->Prev;
			temp->Prev->Next = add;
			return;
		}
		
	}
private:

};