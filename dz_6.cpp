// Создать свой класс вектор на основе класса stl::vector(https://en.cppreference.com/w/cpp/container/vector)
// Реализовать:
//1 -operator[]         +
//2 -operator==
//3 -front()
//4 -back()
//5 -begin()
//6 -end()
//7 -clear()            +
//8 -insert()
//9 -erase()
//10 -push_back()
//11 -pop_back()
//12 -resize()
//13 -empty()
//14 -reserve()
//15 -capacity()         +
//16 -size()             +
//17 -shrink_to_fit()

#include <iostream>
using namespace std;

const int max_size = 100;


template <typename T>
class MyVector
{
private:
    T* arr;
    int capacity; // Вместимость вектора
    int size; // количество элементов
public:
    MyVector()
  {
      arr = new T[1];
      capacity = 1;
      size = 0;
  }
  /////////////////////////////////////////
    void push(T val)
  {
    if (size == capacity)
    {
      T* temp = new T[2 * capacity];
      for (int i = 0; i < size; i++)
      {
        temp[i] = arr[i];
      }
      delete[] arr;
      capacity *= 2;
      arr = temp;
    }
    arr[size] = val;
    size++;
  }
    T get(int index)
  {
    if (index < size)
    {
      return arr[index];
    }
  }
    void pop()
  {
    if (size > 0) 
    {
      size--;
    }
  }
    int get_size()         // Размер вектора
    {
        return size;
    }
    int get_capacity()      // Размер вместимости вектора
    {
        return capacity;
    }
    void show()
  {
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << endl;
    }
  }
///////////////////////////////////////////////
int& operator[] (int index) //operator[]
{
	return arr[index];
}

// bool operator==(T q1)     //Сравнение
// {
//     bool rezz = 0;
//     for (int i = 0; i < size; i++)
//       {
//         rezz = q1[i] == arr[i];
//       }
//     return rezz;
// }

   void clear()
    {   
        arr = NULL;
        capacity = 0;
        size = 0;
        delete[] arr;
    }
 





};





int main()
{
  MyVector<int> v;
  v.push(2);
  //cout << v.get_capacity() << endl;
  v.push(6);
  //cout << v.get_capacity() << endl;
  v.push(10);
  //cout << v.get_capacity() << endl;
  //v.show();
  cout << v[2] << endl;
    cout << v.get_size() << endl;
    v.clear();
    cout << v.get_size() << endl;
    v.show();

  MyVector<int> v1;
  v1.push(2);
  //cout << v.get_capacity() << endl;
  v1.push(6);
  //cout << v.get_capacity() << endl;
  v1.push(10);
  //cout << v.get_capacity() << endl;
  //v.show();
// bool zzz = v == v1;
    //cout << zzz << endl;
    //bool res = v1 == v 


}

