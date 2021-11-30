#pragma once
#include <iostream>
using namespace std;
class Human
{
protected:
  string name;
  int age;
public:
  Human(string, int);
  string getName();
  int getAge();
  void getInfo();
  virtual bool isGood() = 0;
  friend ostream& operator<<(ostream&, Human*&);
};
class Student :public Human
{
private:
  float avg_mark;
public:
  Student(string, int, float);
  void getInfo();
  bool isGood();
  friend ostream& operator<<(ostream&, Human*&);
};
class Teacher :public Human
{
private:
  int number_of_publications;
public:
  Teacher(string, int, int);
  void getInfo();
  bool isGood();
  friend ostream& operator<<(ostream&, Human*&);
};
