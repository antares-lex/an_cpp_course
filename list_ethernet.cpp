// Списки

// 2) Реализовать односвязный список, обладающим следующим функционалом
// -Добавление элементов в конец списка+
// -Добавление элементов в начало списка+
// -Вывод элементов списка+
// -Получение количества элементов списка+
// -Вставление элемента на указанную позицию+
// -Удаление всех элементов+
// -Удаление первого элемента списка+
// -Удаление последнего элемента списка+
// -Удаление элемента на указанной позиции+
// -Удаление элементов в диапозоне между двумя указанными позициями

#include <iostream>
#include <string>
using namespace std;

class List
{
	class Node
	{
	public:
		int data;
		Node* next;
		Node(int t = int(), Node* n = nullptr);
	};
	Node* head;
	int size;

public:
	List();
	~List();
	void pushBack(int value);     // -Добавление элементов в конец списка
	void pushFront(int value);      // -Добавление элементов в начало списка
	int getSize() const;			// -Получение количества элементов списка
	int& operator[] (int);         // -Вывод элементов списка
	void popFront();				// -Удаление первого элемента списка
	void popBack();					// -Удаление последнего элемента списка
	void clear();						// -Удаление всех элементов
	void insert(int value, int index);	// -Вставка элемента на указанную позицию
	void removeAt(int index);			// -Удаление элемента на указанной позиции
	void remove_diap(int frs, int lst); // -Удаление элементов в диапозоне между двумя указанными позициями

};
//void show();

int main()
{

	List list;

	list.pushBack(987);
	list.pushBack(111);
	list.pushBack(222);
	list.pushBack(333);
	list.pushBack(444);
	list.pushBack(555);


	list.remove_diap(4, 3);

	//list.pushFront(444);
	//list.pushFront(555);
	//list.pushFront(666);

	//list.insert(7, 6);

	// cout << list.getSize() << endl;

	// list.clear();


	// cout << list.getSize() << endl;
	// //cout << endl;
	for (int i = 0; i < list.getSize(); i++)
		cout << list[i] << endl;




	//setlocale(0, "");
	//List list;
	//for (int i = 0; i < 5; i++) list.pushBack(i);
	//show();
	//list.popBack();
	//list.popFront();
	//list[1] = 777;
	//show();
	//system("pause");
}

List::Node::Node(int t, Node* n)
{
	data = t;
	next = n;
}

//template<class T>
List::List()
{
	size = 0;
	head = nullptr;
}

//template<class T>
List::~List()
{
	clear();
}

void List::pushBack(int value)
{
	if (head == nullptr)
		head = new Node(value);
	else
	{
		for (Node* current = head; ; current = current->next)
			if (current->next == nullptr)
			{
				current->next = new Node(value);
				break;
			}
	}
	size++;
}

//template<class T>
void List::pushFront(int value)
{
	head = new Node(value, head);
	size++;
}

//template<class T>
int List::getSize() const
{
	return size;
}

//template<class T>
int& List::operator[](int index)
{
	if (index > size - 1 || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	Node* current = head;
	for (int i = 0; i < index; i++)
		current = current->next;
	return current->data;
}

//template<class T>
void List::popFront()
{
	if (size <= 0) return;
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

//template<class T>
void List::popBack()
{
	removeAt(size - 1);
}

//template<class T>
void List::clear()
{
	while (size) popFront();
}

//template<class T>
void List::insert(int value, int index)
{
	if (index > size || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	if (index == 0) pushFront(value);
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->next;
		previous->next = new Node(value, previous->next);
		size++;
	}
}

//template<class T>
void List::removeAt(int index)
{
	if (index > size - 1 || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	if (index == 0) popFront();
	else
	{
		Node* previous = head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->next;
		Node* temp = previous->next;
		previous->next = temp->next;
		delete temp;
		size--;
	}
}

void List::remove_diap(int index_f, int index_l)
{
	if (index_f > size || index_f < 0 || index_f > size || index_f < 0 || index_f > index_l )
		{
			string message = "Недопустимая комбинация индексов ";
			throw out_of_range(message);
		}
	if (index_f == index_l) removeAt(index_f);
	else
	{
		for (int i = 0; i <= index_l-index_f; i++)
			removeAt(index_f);
	}
}

//template<class T>
void show(List& list)
{
	cout << "size = " << list.getSize() << endl;
	for (int i = 0; i < list.getSize(); i++) cout << list[i] << "  ";
	cout << endl;
}