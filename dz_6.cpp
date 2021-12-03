// Создать свой класс вектор на основе класса stl::vector(https://en.cppreference.com/w/cpp/container/vector)
// Реализовать:
//1 -operator[]         +
//2 -operator==         +
//3 -front()            +
//4 -back()             +
//5 -begin()            +
//6 -end()              +
//7 -clear()            +
//8 -insert()           +                     
//9 -erase()            +           
//10 -push_back()       +
//11 -pop_back()        +
//12 -resize()          +
//13 -empty()           +
//14 -reserve()
//15 -capacity()        +
//16 -size()            +
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
    int it_size; // количество элементов
public:

  typedef T* iterator;
    
    MyVector()
  {
      arr = new T[1];
      capacity = 1;
      it_size = 0;
  }
void push_back(T val )
{
    if ( it_size == capacity )
    {
        resize( it_size + 1 );
        --it_size;
    }
 
    arr[it_size++] = val;
}

    void pop_back()
  {
    if (it_size > 0) 
    {
      it_size--;
    }
  }
    int size()         // Размер вектора
    {
        return it_size;
    }
    int get_capacity()      // Размер вместимости вектора
    {
        return capacity;
    }
    void show()
  {
    for (int i = 0; i < it_size; i++)
    {
      cout << arr[i] << endl;
    }
  }
///////////////////////////////////////////////
int& operator[] (int index) //operator[]
{
	return arr[index];
}

bool operator==(MyVector q1)     //Сравнение
{
    bool rezz = 1;
    for (int i = 0; i < it_size; i++)
      {
        rezz = rezz && (q1[i] == arr[i]);
      }
    rezz = rezz && (capacity == q1.capacity) && (it_size == q1.it_size);
    return rezz;
}

   void clear()
    {   
        arr = NULL;
        capacity = 0;
        it_size = 0;
        delete[] arr;
    }
 
int& front() //front()
{
	return arr[0];
}

int& back() //back()
{
	return arr[it_size - 1];
}
 
bool empty() //empty()
{
  return it_size == 0;
}

iterator begin()
{
  return arr; 
}
  
iterator end()
{
  return arr + it_size;
}

void resize( int new_size)
{
    capacity = 2 * new_size;
    T *new_arr = new T[capacity];
    for ( auto i = 0; i != std::min( it_size, new_size ); ++i )
        new_arr[i] = arr[i];
    // for ( auto i = std::min( it_size, new_size ); i != new_size; ++i )
    //     new_arr[i] = c;
 
    delete [] arr;
    it_size = new_size;  
    arr = new_arr;
}

void insert(T val, int index)
{

  if ( it_size == capacity )
  {
    resize( it_size + 1 );
  }
  if (index > it_size- 1|| index < 0)
	{
		string message = "Недопустимый индекс ";
		message.append(to_string(index));
		throw out_of_range(message);
	}
    if (index == it_size)
      push_back(val);
    else
    {
    for (int i = it_size; i > index; i--)
      arr[i] = arr[i-1];
    arr[index] = val;
    }
}

void erase( iterator first, iterator last )
{
    int beg = first - begin();
    int end = last - begin();     
    int _new_size = it_size - end + beg;
    int _new_capacity = 2 * _new_size;
 
    T *_new_arr = new T[_new_capacity];
 
    for ( int i = 0; i != beg; ++i )
        _new_arr[i] = arr[i];
 
    for ( int i = beg, j = end; j != it_size; ++i, ++j )
        _new_arr[i] = arr[j];
 
    delete [] arr;
 
    it_size = _new_size;
    capacity = _new_capacity;
    arr = _new_arr;
    //return begin() + beg;
}





};


// template <typename T>
// typename MyVector<T>::iterator MyVector<T>::begin()
// {
//     return arr; 
// }
 
// template <typename T>
// typename MyVector<T>::iterator MyVector<T>::end() 
// {
//     return arr + size;
// }




int main()
{
  // MyVector<int> v;

  // cout << v.empty() << endl;

  // v.push(2);
  // //cout << v.get_capacity() << endl;
  // v.push(6);
  // //cout << v.get_capacity() << endl;
  // v.push(10);
  // //cout << v.get_capacity() << endl;
  // //v.show();
  // // cout << v[1] << endl;
  
  // //   v.clear();
  // //   cout << v.size() << endl;
  // //   v.show();
  // // cout << v.back() << endl;
  // // cout << v.front() << endl;

  // cout << v.empty() << endl;


  // MyVector<int>::iterator pA;
  // pA = v.end();
	// pA--;
	// cout << *pA << endl;


  MyVector<string> v1;
  v1.push_back("2.1s");
  //cout << v.get_capacity() << endl;
  v1.push_back("6.1");
  //cout << v.get_capacity() << endl;
  v1.push_back("10.1");

  v1.push_back("666.1");
  //cout << v.get_capacity() << endl;
  //v.show();
  //cout << v1[1] << endl;

  // v1.pop_back();
  // v1.pop_back();
   //v1.insert("1111.1",3);
   v1.erase(v1.begin() + 1, v1.begin() + 2);

  for (auto i = v1.begin(); i != v1.end(); i++)
  {

    cout << *i << " ";
  }


  


  // cout << endl;
  // bool zzz = v== v1;
  // cout << zzz << endl;

  // cout << v1.back() << endl;
  // cout << v1.front() << endl;
  //   //bool res = v1 == v 


}
