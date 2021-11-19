#include <iostream>
#include <string>
using namespace std;
class Array
{
private:
    int* data;
    int len;
public:
    Array(int len)
    {
        data = new int[len];
        this->len = len;
    }
    ~Array()
    {
        cout << "dest" << endl;
        delete[] data;  
    }
    void set(int index, int val)
    {
        data[index] = val;
    }

    int get(int index)
    {
        return data[index];
    }
    // Конструктор нужен для создания объектов
    // Диструктор для их удаления
};

// Указатель – переменная, значением которой является адрес ячейки памяти.
// & - операция взятия адреса

int main()
{
    // Array arr(10);
    // arr.set(3, 66);
    // cout << arr.get(3) << endl;

    Array* arr = new Array(10); // объект динамический создан через new, необходимо через операцию delete(вызывается диструктор, чтобы высвобождать память..) если не через нью, тогда не надо высвобождать?
    arr->set(3,66);
    cout << arr->get(3);
    delete arr;
}