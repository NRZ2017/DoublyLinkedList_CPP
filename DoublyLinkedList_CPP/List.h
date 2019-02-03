#pragma once
#include <memory>
#include "Node.h"


using namespace std;

template <typename T>
class List
{
private:
	int count;

public:
	Node<T>* Head;


	List()
	{
		Head == nullptr;
	}

	void AddLast(T value)
	{
		count++;
		if (Head == nullptr)
		{
			Head = new Node<T>(value);
			Head->Next.reset(Head);
			Head->Prev = Head;
			return;
		}

		Node<T>* temp = new Node<T>(value);

		temp->Next = move(Head->Prev->Next);
		temp->Prev = Head->Prev;
		Head->Prev = temp;
	}

	void AddFirst(T value)
	{
		AddLast(value);
		Head = Head->Prev;
	}



	//Circular
	bool RemoveFront()
	{
		if (Head == nullptr)
		{
			return false;
		}

		Node<T>* temp = Head;
		temp = Head->Next.get();
		Head = Head->Next.get();
		Head = temp;
		Head->Prev = nullptr;
		count--;
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
		count--;
		return true;
	}

	//bool Remove(T value)
	//{
	//	if (Head == nullptr)
	//	{
	//		return false;
	//	}
	//	Node<T>* temp = new Node<T>(value);
	//	for (int i = 0; i < count; i++)
	//	{
	//		if (value = temp->Value)
	//		{
	//			temp = temp->Next;
	//			temp->Prev = nullptr;
	//		}
	//	}
	//	return true;
	//}

	/*void Clear()
	{
		Head = nullptr;
		Head->Next.reset();
		Head->Prev = nullptr();
		count = 0;
	}

	bool Contains(T value)
	{
		return find(value) != nullptr;
	}*/

};
