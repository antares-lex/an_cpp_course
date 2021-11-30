
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//class B;
//class A
//{
//private:
//  int a;
//public:
//  A()
//  {
//    a = 1;
//  }
//  friend int func(A, B);
//};
//class B
//{
//private:
//  int b;
//public:
//  B()
//  {
//    b = 2;
//  }
//  friend int func(A, B);
//};
//int func(A a_obj, B b_obj)
//{
//  return a_obj.a + b_obj.b;
//}
class Time
{
private:
  int min, sec;
public:
  Time(int min=0, int sec=0)
  {
    this->min = min;
    this->sec = sec;
  }

  friend ostream& operator<<(ostream&, Time*&);
  friend istream& operator>>(istream&, Time*&);
};
ostream& operator<<(ostream& s, Time*& t)
{
  s << t->min << " " << t->sec << endl;
  return s;
}
istream& operator>>(istream& s, Time*& t)
{
  cout << "Enter minutes and seconds" << endl;
  s >> t->min>>t->sec;
  return s;
}
int main()
{



  Time *t = new Time(20,25);
 
  cin >> t;
 
  cout << t;


    // int var1 = 123; // инициализация переменной var1 числом 123
    // int var2 = 99; // инициализация переменной var2 числом 99
    // int *ptrvar1 = &var1; // указатель на переменную var1
    // int *ptrvar2 = &var2; // указатель на переменную var2
    // cout << "var1    = " << var1 << endl;
    // cout << "var2    = " << var2 << endl;
    // cout << "ptrvar1 = " << ptrvar1 << endl;
    // cout << "ptrvar2 = " << ptrvar2 << endl;
    // if (ptrvar1 > ptrvar2) // сравниваем значения указателей, то есть адреса переменных
    //     cout << "ptrvar1 > ptrvar2" << endl;
    // if (*ptrvar1 > *ptrvar2) // сравниваем значения переменных, на которые ссылаются указатели
    //     cout << "*ptrvar1 > *ptrvar2" << endl;

  //ofstream out("file.txt");
 
   //Time *t = new Time(20,25);
 
//   //cin >> t;
 
   //cout << t->;
 
  //out.close();
  //cout << t;
  ////////////////////////////////
  //A a_obj;
  //B b_obj;
  //cout << func(a_obj, b_obj);
}