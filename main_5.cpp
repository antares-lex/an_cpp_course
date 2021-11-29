// Полиморфизм - возможность иметь одинаковый интерфейс, но совершенно разную реализацию 
//               один интерфейс и множнство методов

#include <iostream>
#include <string>
using namespace std;
//class Parent
//{
//public:
//  virtual void show() = 0;
//  //{
//  //  cout << "Parent" << endl;
//  //}
//};
//class Child_1 : public Parent
//{
//public:
//  void show()
//  {
//    cout << "Child_1" << endl;
//  }
//};
//class Child_2 : public Parent
//{
//public:
//  void show()
//  {
//    cout << "Child_2" << endl;
//  }
//};
////////////////////////////////////
class Human
{
protected:
  string name;
  int age;
public:
  Human(string name, int age)
  {
    this->name = name;
    this->age = age;
  }
  string getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
  void getInfo()
  {
    cout << getName() << " " << getAge() << endl;
  }
  virtual bool isGood() = 0;
};
class Student:public Human
{
private:
  float avg_mark;
public:
  Student(string name = "Student", int age = 15, float avg_mark = 4.5) :Human(name, age)
  {
    this->avg_mark = avg_mark;
  }
  void getInfo()
  {
    Human::getInfo();
    cout <<"Mark: "<< avg_mark << endl;
  }
  bool isGood() 
  { 
    return avg_mark >= 4;
  }
};
class Teacher:public Human
{
private:
  int number_of_publications;
public:
  Teacher(string name = "Teacher", int age = 34, int number_of_publications = 4) :Human(name, age)
  {
    this->number_of_publications = number_of_publications;
  }
  void getInfo()
  {
    Human::getInfo();
    cout << "Number of publications: " << number_of_publications << endl;
  }
  bool isGood()
  {
    return number_of_publications >= 5;
  }
};
int main()
{
  //Human H("asd", 10);  
  Human* people[100];
  int current_number = 0;
  while (true)
  {
    char choice;
    cout << "Teacher[t] or Student[s]?" << endl;
    cin >> choice;
    if (choice == 't')
    {
      string name;
      cout << "Name: ?" << endl;
      cin >> name;

      int age;
      cout << "Age: ?" << endl;
      cin >> age;

      int number_of_publications;
      cout << "Number of publications: ?" << endl;
      cin >> number_of_publications;

      people[current_number++] = new Teacher(name, age, number_of_publications);
    }
    else if (choice == 's')
    {
      string name;
      cout << "Name: ?" << endl;
      cin >> name;

      int age;
      cout << "Age: ?" << endl;
      cin >> age;

      float avg_mark;
      cout << "Average mark: ?" << endl;
      cin >> avg_mark;

      people[current_number++] = new Student(name, age, avg_mark);
    }
    else
    {
      cout << "wrong input" << endl;
    }
    cout << "Do you want to add another person [y] [n]?: " << endl;
    cin >> choice;
    if (choice == 'n')
    {
      break;
    }
  }

  for (int i = 0; i < current_number; i++)
  {
    if (people[i]->isGood())
    {
      cout << "This person is good"<<endl;
      people[i]->getInfo();
      cout << "_______________" << endl;
    }
  }
  ///////////////////////////////////
  /*Child_1 c1;
  Child_2 c2;*/
  //Parent* ptr;
  //ptr = &c1;
  //ptr->show();
  //ptr = &c2;
  //ptr->show();
  //Parent p;
  //p = c1;
  //p.show();
  //p.show();
  //Parent* arr[2];
  //arr[0] = &c1;
  //arr[1] = &c2;
  //for (int i = 0; i < 2; i++)
  //{
  //  arr[i]->show();
  //}
  //Parent p;
  //p.show();
}
