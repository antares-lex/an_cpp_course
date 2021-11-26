#include <iostream>
#include <string>
using namespace std;

class List
{
	class Link
	{
	public:
		int data;
		Link* next;
		Link(int t, Link* n = nullptr);
	};
	Link* head;
	int size;

public:
	List();
	~List();
	void add_back(int val);     		// -Добавление элементов в конец списка
	void add_front(int val);      		// -Добавление элементов в начало списка
	int& operator[] (int);         		// -Вывод элементов списка 
	int get_size() const;				// -Получение количества элементов списка 
	void insert(int val, int index);	// -Вставка элемента на указанную позицию 
	void del_all();						// -Удаление всех элементов  
	void del_first();					// -Удаление первого элемента списка 
	void del_last();					// -Удаление последнего элемента списка 
	void del_index(int index);			// -Удаление элемента на указанной позиции
	void del_diap(int frs, int lst); 	// -Удаление элементов в диапозоне между двумя указанными позициями

};

List::Link::Link(int t, Link* n)
{
	data = t;
	next = n;
}
List::List()
{
	size = 0;
	head = nullptr;
}
List::~List()
{
	del_all();
}
void List::add_back(int val)
{
	if (head == nullptr)
		head = new Link(val);
	else
	{
		for (Link* current = head; ; current = current->next)
			if (current->next == nullptr)
			{
				current->next = new Link(val);
				break;
			}
	}
	size++;
}
void List::add_front(int val)
{
	head = new Link(val, head);
	size++;
}
int& List::operator[](int index)
{
	if (index > size - 1 || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	Link* current = head;
	for (int i = 0; i < index; i++)
		current = current->next;
	return current->data;
}
int List::get_size() const
{
	return size;
}
void List::insert(int val, int index)
{
	if (index > size || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	if (index == 0) add_front(val);
	else
	{
		Link* previous = head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->next;
		previous->next = new Link(val, previous->next);
		size++;
	}
}
void List::del_all()
{
	while (size) del_first();
}
void List::del_first()
{
	if (size <= 0) return;
	Link* temp = head;
	head = head->next;
	delete temp;
	size--;
}
void List::del_last()
{
	del_index(size - 1);
}
void List::del_index(int index)
{
	if (index > size - 1 || index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
	if (index == 0) del_first();
	else
	{
		Link* previous = head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->next;
		Link* temp = previous->next;
		previous->next = temp->next;
		delete temp;
		size--;
	}
}
void List::del_diap(int index_f, int index_l)
{
	if (index_f > size || index_f < 0 || index_f > size || index_f < 0 || index_f > index_l )
		{
			string message = "Недопустимая комбинация индексов ";
		}
	if (index_f == index_l) del_index(index_f);
	else
	{
		for (int i = 0; i <= index_l-index_f; i++)
			del_index(index_f);
	}
}

int main()
{

}