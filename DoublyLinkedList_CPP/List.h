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
		std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(value);
		//Node<T>* temp = new Node<T>(value);

		temp->Next = move(tail->Next);
		temp->Prev = move(Head->Prev);

		tail->Next = temp;
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
		if (count == 1)
		{
			Head = nullptr;
			return true;
		}

		std::shared_ptr<Node<T>> next = Head->Next;
		Node<T>* prev = Head->Prev.get();

		next->Prev = move(Head->Prev);
		prev->Next = move(Head->Next);

		//delete Head; //possibly not required?

		Head = next;
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
