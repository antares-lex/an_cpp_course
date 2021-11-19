// Списки
#include <iostream>
using namespace std;

struct Link
{
    int data;
    Link* next;
};

class List
{
private:
    Link* current;
public:
    List()
    {
        current = nullptr;
    }
void add_item(int);
void show();
};


void List::add_item(int val)
{
    Link* new_link = new Link;
    new_link->data = val;
    new_link->next = current;
    current = new_link;
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
    List list;
    list.add_item(3);
    list.add_item(5);
    list.add_item(99);
    list.add_item(133);
    list.show();
    list.show();

// Результат
// 133
// 99
// 5
// 3

}