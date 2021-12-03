#include <iostream>
#include <stdexcept>
#include <utility>
using std::rel_ops::operator!=;
using std::rel_ops::operator>;
using std::rel_ops::operator<=;
using std::rel_ops::operator>=;
 
template <typename T> 
class mvector
{
public:
    typedef size_t size_type;
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator; 
    explicit mvector();
    explicit mvector( size_type, const T& val = T() );
    mvector( const mvector<T>& );
    mvector( iterator, iterator );
    ~mvector();
    size_type size() const;
    size_type capacity() const;
    void resize( size_type, T = T() );
    void assign( iterator first, iterator last );
    void assign (size_type n, const T& u );
    void push_back( const T& );
    void pop_back();
    iterator erase( iterator );
    iterator erase( iterator, iterator );
    iterator insert( iterator, const T& );
    void insert( iterator, size_type, const T& );
    void insert( iterator, iterator, iterator );
    void clear();
    void swap( mvector<T>& ); 
    T& front();
    T& back();
    T& at( size_type );
    const T& at( size_type ) const;
    bool empty() const;
    const mvector& operator= ( const mvector& );
    const T& operator[] ( size_type ) const;
    T& operator[] ( size_type );
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
private:
    size_type _size;    
    size_type _capacity;    
    T *_arr;
};
 
template <typename T>
mvector<T>::mvector():
_size( 0 ), _capacity( 2*_size ), _arr( nullptr )
{
}   
 
template <typename T>
mvector<T>::mvector( size_type num, const T& val ):
_size( num ), _capacity( 2*_size ), _arr( new T[_capacity] )
{
    for ( size_type i = 0; i != _size; ++i )
        _arr[i] = val;
}
 
template <typename T>
mvector<T>::mvector( const mvector<T>& c ):
_size( c._size ), _capacity( c._capacity ), _arr( new T[_capacity] )
{
    for ( size_type i = 0; i != _size; ++i )
        _arr[i] = c._arr[i];
}
 
template <typename T>
mvector<T>::mvector( iterator start, iterator end ):
_size( end - start ), _capacity( 2*_size ), _arr( new T[_capacity] )
{
    for ( size_type i = 0; i != _size && start != end; ++i )
        _arr[i] = *start++;
}
 
template <typename T>
mvector<T>::~mvector()
{
    delete [] _arr;
}
 
template <typename T>
typename mvector<T>::size_type mvector<T>::size() const
{
    return _size;
}
 
template <typename T>
typename mvector<T>::size_type mvector<T>::capacity() const
{
    return _capacity;
}
 
template <typename T>
void mvector<T>::resize( size_type _new_size, T c )
{
    _capacity = 2 * _new_size;
    T *_new_arr = new T[_capacity];
    for ( size_type i = 0; i != std::min( _size, _new_size ); ++i )
        _new_arr[i] = _arr[i];
    for ( size_type i = std::min( _size, _new_size ); i != _new_size; ++i )
        _new_arr[i] = c;
 
    delete [] _arr;
    _size = _new_size;  
    _arr = _new_arr;
}
 
template <typename T>
void mvector<T>::assign( iterator first, iterator last )
{
    delete [] _arr;
    _size = last - first;
    _capacity = 2*_size;
    _arr = new T[_capacity];
    for ( size_type i = 0; i != _size && first != last; ++i )
        _arr[i] = *first++;
}
 
template <typename T>
void mvector<T>::assign( size_type n, const T& u )
{
    delete [] _arr;
    _size = n;
    _capacity = 2*_size;
    _arr = new T[_capacity];
    for ( size_type i = 0; i != _size; ++i )
        _arr[i] = u;
}
 
template <typename T>
void mvector<T>::push_back( const T& val )
{
    if ( _size == _capacity )
    {
        resize( _size + 1 );
        --_size;
    }
 
    _arr[_size++] = val;
}
 
template <typename T>
void mvector<T>::pop_back()
{
    if ( _size > 0 )
        --_size;
}
 
template <typename T>
typename mvector<T>::iterator mvector<T>::erase( iterator position )
{
    for ( iterator i = position; i != end(); ++i )
        *i = *( i + 1 );
    --_size;
    return position;
}
 
template <typename T>
typename mvector<T>::iterator mvector<T>::erase( iterator first, iterator last )
{
    size_type beg = first - begin();
    size_type end = last - begin();     
    size_type _new_size = _size - end + beg;
    size_type _new_capacity = 2 * _new_size;
 
    T *_new_arr = new T[_new_capacity];
 
    for ( size_type i = 0; i != beg; ++i )
        _new_arr[i] = _arr[i];
 
    for ( size_type i = beg, j = end; j != _size; ++i, ++j )
        _new_arr[i] = _arr[j];
 
    delete [] _arr;
 
    _size = _new_size;
    _capacity = _new_capacity;
    _arr = _new_arr;
    return begin() + beg;
}
 
template <typename T>
typename mvector<T>::iterator mvector<T>::insert( iterator position, const T& x )
{
    size_type tmp = position - begin();
    if ( _size + 1 > _capacity )
        resize( _size + 1 );
    else
        ++_size;
    position = begin() + tmp;
    for ( iterator i = end() - 1; i != position; --i )
        *i = *( i - 1 );
    *position = x;
    return position;
}
 
template <typename T>
void mvector<T>::insert( iterator position, size_type n, const T& x )
{
    size_type tmp = position - begin();
    if ( _size + n > _capacity )
        resize( _size + n );
    else
        _size += n;
    position = begin() + tmp;
    for ( iterator i = end() - 1; i != position + n - 1; --i )
        *i = *( i - n );
    for ( iterator i = position; i != position + n; ++i )
        *i = x;
}
 
template <typename T>
void mvector<T>::insert( iterator position, iterator first, iterator last )
{
    size_type tmp = position - begin();
    size_type n = last - first;
    if ( _size + n > _capacity )
        resize( _size + n );    
    else
        _size += n;
    position = begin() + tmp;
    for ( iterator i = end() - 1; i != position + n - 1; --i )
        *i = *( i - n );
    for ( iterator i = position; i != position + n && first != last; ++i )
        *i = *first++;
}
 
template <typename T>
void mvector<T>::clear() 
{
    delete [] _arr;
    _arr = nullptr;
    _size = 0;
    _capacity = 0;
}
 
template <typename T>
void mvector<T>::swap( mvector<T>& c ) 
{ 
    if ( *this != c )
    {
        std::swap( _size, c._size );
        std::swap( _capacity, c._capacity );
        std::swap( _arr, c._arr );
    }
}
 
template <typename T>
T& mvector<T>::at( size_type index )
{
    if ( index >= _size )
        throw std::out_of_range( "Expression: vector subscript out of range." );
    return _arr[index];
}
 
template <typename T>
const T& mvector<T>::at( size_type index ) const
{
    if ( index >= _size )
        throw std::out_of_range( "Expression: vector subscript out of range." );
    return _arr[index];
}
 
template <typename T>
T& mvector<T>::front()
{
    return at( 0 );
}
 
template <typename T>
T& mvector<T>::back()
{
    return at( _size - 1 );
}
 
template <typename T>
bool mvector<T>::empty() const
{
    return _size == 0;
}
 
template <typename T>
const mvector<T>& mvector<T>::operator= ( const mvector<T>& c )
{
    if ( *this != c )
    {
        _size = c._size;
        _capacity = c._capacity;
        delete [] _arr;
        _arr = new T[_capacity];
        for ( size_type i = 0; i != c._size; ++i )
            _arr[i] = c._arr[i];
    }
 
    return *this;
}
 
template <typename T>
const T& mvector<T>::operator[] ( size_type n ) const
{
    return _arr[n];
}
 
template <typename T>
T& mvector<T>::operator[] ( size_type n )
{   
    return _arr[n];
}
 
template <typename T>
bool operator== ( const mvector<T>& c1, const mvector<T>& c2 )
{
    if (c1.size() != c2.size())
        return false;
    else
    {
        for ( int i = 0; i != c1.size(); ++i )
            if ( c1[i] != c2[i] )
                return false;
    }
    return true;
}
 
template <typename T>
bool operator< ( const mvector<T>& c1, const mvector<T>& c2 )
{
    if (c1.size() != c2.size())
        return c1.size() < c2.size();
    else
    {
        for ( int i = 0; i != c1.size(); ++i )
            if ( c1[i] != c2[i] )
                return c1[i] < c2[i];
    }
    return false;
}
 
template <typename T>
typename mvector<T>::iterator mvector<T>::begin()
{
    return _arr; 
}
 
template <typename T>
typename mvector<T>::const_iterator mvector<T>::begin() const 
{
    return _arr; 
}
 
template <typename T>
typename mvector<T>::iterator mvector<T>::end() 
{
    return _arr + _size;
}
 
template <typename T>
typename mvector<T>::const_iterator mvector<T>::end() const 
{ 
    return _arr + _size; 
}

// int main()
// {
//   mvector<int> v;


//   v.push_back(3);
//   //cout << v.get_capacity() << endl;
//   v.push_back(6);
//   //cout << v.get_capacity() << endl;
//   v.push_back(10);
//   //cout << v.get_capacity() << endl;
  
//   for (auto i = v.begin(), i = v.end(), i++)
//   {
//     cout << v[i] << endl;
//   }


// }