#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Figure
{
protected:
  string name;
  string type;
public:
  Figure(string name)
  {
    this->name = name;
    this->type = "Figure";
  }
  string get_name()
  {
    return name;
  }
  string get_type()
  {
    return type;
  }
  void show()
  {
    cout << "Name of figure is: " + get_name() << " Type of figure is: " << Figure::get_type() << endl;
  }
};

class Square: public Figure
{
protected:
  double a;
public:
  Square(string name, double a):Figure(name)
  {
    this -> a = a;
    this -> type = "Square";
  }
  double get_square()
  {
    return a * a;
  }
  double get_perimeter()
  {
    return 4 * a;
  }
};

class Rectangle: public Square
{
protected:
  double b;
public:
  Rectangle(string name, double a, double b):Square(name, a)
  {
    this -> b = b;
    this -> type = "Rectangle";
  }
  double get_square()
  {
    return a * b;
  }
  double get_perimeter()
  {
    return 2*a + 2*b;
  }
};

class Triangle: public Rectangle
{
protected:
  double c;
public:
  Triangle(string name, double a, double b, double c):Rectangle(name, a, b)
  {
    this -> c = c;
    this -> type = "Triangle";
  }
  double get_square()
  {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }
  double get_perimeter()
  {
    return a + b + c;
  }
};

class Circle: public Figure
{
protected:
const double pi = 3.14;
    double r;
public:
  Circle(string name, double r):Figure(name)
  {
    this -> r = r;
    this -> type = "Circle";
  }
  double get_square()
  {
    return pi*r*r;
  }
  double get_perimeter()
  {
    return 2*pi*r;
  }
};

class Cube: public Square
{
public:
  Cube(string name, double a):Square(name, a)
  {
    this -> type = "Cube";
  }
  double get_square()
  {
    return Square::get_square() * 6;
  }
  double get_perimeter()
  {
    return 12 * a;
  }
  double get_volume()
  {
    return a * a * a;
  }
};

class Sphere: public Circle
{
public:
  Sphere(string name, double r):Circle(name, r)
  {
    this -> type = "Sphere";
  }
  double get_square()
  {
    return 4 * Circle::get_square();
  }
  double get_volume()
  {
    return get_square() * r / 3;
  }
 };


