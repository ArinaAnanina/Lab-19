#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct StackItem
{
	T* data;
	StackItem<T>* next;
	StackItem(T* Data, StackItem<T>* Next)
	{
		this->data = Data;
		this->next = Next;
	}
	~StackItem() {
		delete this->data; 
	} 
};

template <typename T>
class Stack
{
	int size;
	StackItem<T>* first;
public:
	Stack(int size)
	{
		this->first = 0;
		this->size = 0;
		for (int i = 0; i < size; i++) {
			T* data = new T;
			cout << "Введите " << i + 1 << " элемент: " << endl;
			cin >> (*data);
			this->Push(data);
		}
	}
	Stack(Stack<T>& list)
	{
		this->first = 0;
		this->size = 0;

		StackItem<T>* item = list.first;
		while (item) {
			T* data = new T(*item->data);
			this->Push(data);
			item = item->next;
		}
	}
	~Stack()
	{
		StackItem<T>* current = this->first;
		while (current) {
			StackItem<T>* rem = current;
			current = current->next;
			delete rem;
		}
	}

	void Push(T* value)
	{
		StackItem<T>* item = new StackItem<T>(value, this->first);
		this->first = item;
		this->size++;
	}
	void Push(const T& value)
	{
		T* val = new T(value);
		this->Push(val);
	}
	int Size() 
	{ 
		return size; 
	}
	bool Empty()
	{
		return this->first == nullptr;
	}
	void Pop()
	{
		if (Empty())
		{
			return;
		}
		StackItem<T>* tmp = this->first;
		this->first = this->first->next;
		delete tmp;
	}
	T& Top()
	{
		if (Empty())
		{
			throw;
		}
		return *this->first->data;
	}
};