
#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
private:
  T* arr;
  int it_capacity; 
  int it_size;
public:
  typedef T* iterator;
  MyVector()
  {
    arr = new T[1];
    it_capacity = 1;
    it_size = 0;
  }
int& operator[] (int index)
{
	return arr[index];
}
bool operator==(MyVector q1)  
{
  bool rezz = 1;
  for (int i = 0; i < it_size; i++)
    {
      rezz = rezz && (q1[i] == arr[i]);
    }
  rezz = rezz && (it_capacity == q1.it_capacity) && (it_size == q1.it_size);
  return rezz;
}
int& front() 
{
	return arr[0];
}
int& back() 
{
	return arr[it_size - 1];
}
iterator begin()
{
  return arr; 
}  
iterator end()
{
  return arr + it_size;
}
void clear()
{   
  arr = NULL;
  it_capacity = 0;
  it_size = 0;
  delete[] arr;
}
void insert(T val, int index)
{
    if ( it_size == it_capacity )
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
    it_capacity = _new_capacity;
    arr = _new_arr;
}
void push_back(T val )
{
  if ( it_size == it_capacity )
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
void resize( int new_size)
{
    it_capacity = 2 * new_size;
    T *new_arr = new T[it_capacity];
    for ( auto i = 0; i != std::min( it_size, new_size ); ++i )
        new_arr[i] = arr[i];
    delete [] arr;
    it_size = new_size;  
    arr = new_arr;
}    
bool empty()
{
  return it_size == 0;
}
int reserve(int increase_capacity)
{
  return it_capacity = increase_capacity;
}
int capacity() 
{
  return it_capacity;
}
int size()      
{
  return it_size;
}
int shrink_to_fit()
{
  return it_capacity = it_size;
}
};

int main()
{
  
}
