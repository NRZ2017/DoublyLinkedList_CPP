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
	std::shared_ptr<Node<T>> Head;

	List()
	{
		Head = nullptr;
	}

	void AddLast(T value)
	{
		count++;
		if (Head == nullptr)
		{

			Head = std::make_shared<Node<T>>(value);
			Head->Next = Head;
			Head->Prev = Head;
			return;
		}

		Node<T>* tail = Head->Prev.get();
		Node<T>* temp = new Node<T>(value);

		temp->Next = move(tail->Next);
		temp->Prev = move(Head->Prev);

		tail->Next.reset(temp);
		Head->Prev.reset(temp);
	}

	void AddFirst(T value)
	{
		AddLast(value);
	  Head.reset(Head->Prev.get());
	}

	//Circular
	bool RemoveFront()
	{
		if (Head == nullptr)
		{
			return false;
		}
		if (count == 1)
		{
			Head->Next.reset();
			Head->Prev.reset();
			return true;
		}

		Node<T>* next = Head->Next.get();
		Node<T>* prev = Head->Prev.get();

		next->Prev = move(Head->Prev);
		prev->Next = move(Head->Next);

		//delete Head; //possibly not required?

		Head.reset(next);
		count--;
		return true;
	}

	bool RemoveEnd()
	{
		if (Head == nullptr)
		{
			return false;
		}

		Node<T>* tail = Head->Prev.get();
		Node<T>* before = Head->Prev->Prev.get();
		before->Next = tail->Next;
		Head->Prev = tail->Prev;
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
