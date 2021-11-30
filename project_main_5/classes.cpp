#include "classes.h"
#include <iostream>
using namespace std;
Human::Human(string name, int age)
{
  this->name = name;
  this->age = age;
}

string Human::getName()
{
  return name;
}
int Human::getAge()
{
  return age;
}
void Human::getInfo()
{
  cout << getName() << " " << getAge() << endl;
}

Student::Student(string name = "Student", int age = 15, float avg_mark = 4.5) :Human(name, age)
{
  this->avg_mark = avg_mark;
}
void Student::getInfo()
{
  Human::getInfo();
  cout << "Mark: " << avg_mark << endl;
}
bool Student::isGood()
{
  return avg_mark >= 4;
}
ostream& operator<<(ostream& out, Student*& s)
{
  out << s->getName() << " " << s->getAge()<<endl;
  return out;
}

Teacher::Teacher(string name = "Teacher", int age = 34, int number_of_publications = 4) :Human(name, age)
{
  this->number_of_publications = number_of_publications;
}
void Teacher::getInfo()
{
  Human::getInfo();
  cout << "Number of publications: " << number_of_publications << endl;
}
bool Teacher::isGood()
{
  return number_of_publications >= 5;
}
ostream& operator<<(ostream& out, Human*& h)
{
  out << h->getName() << " " << h->getAge() << endl;
  if (dynamic_cast<Student*>(h))
  {
    out << (dynamic_cast<Student*>(h))->avg_mark << endl;
  }
  else if (dynamic_cast<Teacher*>(h))
  {
    out << (dynamic_cast<Teacher*>(h))->number_of_publications << endl;
  }
  return out;
}
