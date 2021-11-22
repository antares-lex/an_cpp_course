// Списки

// 2) Реализовать односвязный список, обладающим следующим функционалом
// -Добавление элементов в конец списка
// -Добавление элементов в начало списка +
// -Вывод элементов списка +
// -Получение количества элементов списка +
// -Вставление элемента на указанную позицию
// -Удаление всех элементов
// -Удаление первого элемента списка
// -Удаление последнего элемента списка
// -Удаление элемента на указанной позиции
// -Удаление элементов в диапозоне между двумя указанными позициями

#include <iostream>
using namespace std;

struct Link
{
    int data;
    Link* next;
};

// struct list {
//     Link* first;
//     Link* last;

//     list() : first(nullptr), last(nullptr) {}
// };

class List        // Класс описывающий список
{
private:
    Link* current;
    int size = 0;
public:
    List()
    {
        current = nullptr;
    }
    //Link& operator[] (const int index);
int get_size(){return size;}
void add_item(int);
void add_back(int);
int& operator[](int);
void show();

};

int& List::operator[](const int index)
{
    //cout << "Сработала перегрузка" << endl;
    Link* temp = this->current;
      for (int i = 0; i < index; i++) {
          temp = temp->next;
      }
      return temp->data;
}

void List::add_back(int val)
{
	if (current == nullptr)
    // {
	// 	current = new Link;
    //     current->data = val;
    //     cout << "PFnull" << current->data << endl;
    //     //current->next = current;
    // }
    // else
	{
        Link* new_link = this -> current;
        while (new_link -> next != nullptr)
        {
            new_link = new_link -> next;
            //new_link->data = val;
        }
        new_link->next = new Link;
        new_link->data = val;
        //new_link->next = current;
       // current = new_link;

        
        cout << "PF" << new_link->data << endl;
        //current = new_link;
        //current = new_link;
        //new_link->next = current;
        //current = new_link;
        //new_link->next = current;
		//for (Link* new_link = current; ; new_link = new_link->next)
		// 	if (new_link->next == nullptr)
		// 	{
		//new_link = new Link;
        //         new_link->data = val;
        //         new_link->next = current;
		// 		break;
		// 	}
	}
	size++;
}


void List::add_item(int val)
{
    //cout << "Добавилось!" << endl;
    Link* new_link = new Link;
    //cout << &new_link->next << endl;
    new_link->data = val;
    new_link->next = current;
    current = new_link;
    size++;
}

void List::show()
{
    Link* temp = current;
    while(temp)
    {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}


int main()
{


// int value = 8;
// int &ref = value;

// cout << value << endl;

// cout << &ref <<endl;

    List list;

    // list.add_item(102);
    // cout << list.get_size() << endl;
    list.add_back(100);
    list.add_back(101);
    list.add_back(102);
    // list.add_back(103);
    // list.add_back(104);

    // list.add_item(555);
    // list.add_item(556);

    //list[0];
    //cout << list[0] << endl;
    //cout << list[1] << endl;
    //cout << list[2] << endl;
    //cout << list[3] << endl;
    //cout << list[4] << endl;
    // list.add_item(133);
    // list.show();

    //cout << list.get_size() << endl;

     for(int i=0; i<list.get_size(); i++)
        cout<<list[i]<<endl;

// Результат
// 133
// 99
// 5
// 3

}