#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

private:
    template<typename T>
    class Node // Узел - то есть элементарная единица состоящая из адреса и данных
    {
        public:
            Node *pNext;
            T data;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

List::~List()
{
    
}


int main()
{

}