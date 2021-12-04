#include "classes.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

Figure::Figure(string name)
{
    this->name = name;
}
string Figure::get_name()
{
    return name;
}
void Figure::show()
{
    cout << "Name of figure is: " + get_name() << " Type of figure is: " << get_type() << endl;
}

Square::Square(string name, double a):Figure(name)
{
    this -> a = a;
}
string Square::get_type()
{
    return "Square";  
}
double Square::get_square()
{
    return a * a;
}
double Square::get_perimeter()
{
    return 4 * a;
}

Rectangle::Rectangle(string name, double a, double b):Square(name, a)
{
    this -> b = b;
}
void Rectangle::set_name(string _name, double _a)
{
    name = _name;
    a = _a;
}
string Rectangle::get_type()
{
    return "Rectangle";  
}
double Rectangle::get_square()
{
    return a * b;
}
double Rectangle::get_perimeter()
{
    return 2*a + 2*b;
}

Triangle::Triangle(string name, double a, double b, double c):Rectangle(name, a, b)
{
    this -> c = c;
}
string Triangle::get_type()
{
    return "Triangle";  
}
double Triangle::get_square()
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
double Triangle::get_perimeter()
{
    return a + b + c;
}

Circle::Circle(string name, double r):Figure(name)
{
    this -> r = r;
}
string Circle::get_type()
{
    return "Circle";  
}
double Circle::get_square()
{
    return pi*r*r;
}
double Circle::get_perimeter()
{
    return 2*pi*r;
}

Cube::Cube(string name, double a):Square(name, a){}
string Cube::get_type()
{
    return "Cube";  
}
double Cube::get_square()
{
    return Square::get_square() * 6;
}
double Cube::get_perimeter()
{
    return 12 * a;
}
double Cube::get_volume()
{
    return a * a * a;
}

Sphere::Sphere(string name, double r):Circle(name, r){}
string Sphere::get_type()
{
    return "Sphere";  
}
double Sphere::get_square()
{
    return 4 * Circle::get_square();
}
double Sphere::get_volume()
{
    return get_square() * r / 3;
}

ostream& operator<<(ostream& s, Figure*& t)
{
  s << "Name of figure is: " << t -> get_name() << " " << " Type of figure is: " << t -> get_type() << " Area of figure is: " << t -> get_square() << endl;
  return s;
}
istream& operator>>(istream& s, Figure*& t)
{
  cout << "Enter name of figure" << endl;
  s >> t -> name ;
  return s;
}
istream& operator>>(istream& s, Square*& t)
{
  cout << "Enter name of Square and a = " << endl;
  s >> t -> name >> t -> a;
  return s;
}
istream& operator>>(istream& s, Rectangle*& t)
{
  cout << "Enter name of Rectangle and sides a =, b =" << endl;
  s >> t -> name >> t -> a >> t -> b;
  return s;
}
istream& operator>>(istream& s, Triangle*& t)
{
  cout << "Enter name of Triangle and sides a =, b =, c = "<< endl;
  s >> t -> name >> t -> a >> t -> b >> t -> c;
  return s;
}
istream& operator>>(istream& s, Circle*& t)
{
  cout << "Enter name of Circle and radius r = " << endl;
  s >> t -> name >> t -> r;
  return s;
}
istream& operator>>(istream& s, Cube*& t)
{
  cout << "Enter name of Cube and a = " << endl;
  s >> t -> name >> t -> a;
  return s;
}
istream& operator>>(istream& s, Sphere*& t)
{
  cout << "Enter name of Sphere and radius r = " << endl;
  s >> t -> name >> t -> r;
  return s;
}
