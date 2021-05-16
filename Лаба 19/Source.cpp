#include <iostream>
#include "Header.h"
using namespace std;
template <typename T>
void Show(Stack<T>& list)
{
	int i = 0;
	Stack<T> tmp(list);
	while (!tmp.Empty())
	{
		cout << i + 1 << "элемент: " << tmp.Top() << endl;
		tmp.Pop();
		i++;
	}
}
int main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	Stack<int> list(5);
	cout << "Size:" << list.Size() << endl;
	list.Push(new int(2));
	list.Push(6);
	Stack<int> list2(list);
	Stack<int> list3(4);

	cout << "List1(в конец, с помощью метода Push, добавлены 2 и 6): " << endl;
	Show(list);
	cout << "List2(создан с помощью конструктора копирования): " << endl;
	Show(list2);
	cout << "List3: " << endl;
	Show(list3);
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	list.Pop();
	cout << "Проверка метода, возвращающего информацию пуст ли стек или нет: " << endl;
	if (!list.Empty())
		cout << list.Top();
	else
		cout << "Стек пуст!" << endl;

	return 0;
}