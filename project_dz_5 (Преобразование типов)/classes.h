#pragma once
#include <iostream>
using namespace std;
const double pi = 3.14;
class Figure
{
protected:
    string name;
public:
    Figure(string);
    string get_name();
    virtual double get_square() = 0;
    virtual string get_type() = 0;
    void show();
    friend ostream& operator<<(ostream&, Figure*&);
    friend istream& operator>>(istream&, Figure*&);
};
class Square: public Figure
{
protected:
    double a;
public:
    Square(string, double);
    virtual string get_type();
    double get_square();
    double get_perimeter();
    friend istream& operator>>(istream&, Figure*&);
};
class Rectangle: public Figure
{
protected:
    double a;
    double b;
public:
    Rectangle(string, double, double);
    void set_name(string _name, double _a);
    virtual string get_type();
    double get_square();
    double get_perimeter();
    friend istream& operator>>(istream&, Figure*&);
};
class Triangle: public Figure
{
protected:
    double a;
    double b;
    double c;
public:
    Triangle(string, double, double, double);
    virtual string get_type();
    double get_square();
    double get_perimeter();
    friend istream& operator>>(istream&, Figure*&);
};
class Circle: public Figure
{
protected:
    double r;
public:
    Circle(string, double);
    virtual string get_type();
    double get_square();
    double get_perimeter();
    friend istream& operator>>(istream&, Figure*&);
};
class Cube: public Figure
{
protected:
    double a;
public:
    Cube(string, double);
    virtual string get_type();
    double get_square();
    double get_perimeter();
    double get_volume();
    friend istream& operator>>(istream&, Figure*&);
};
class Sphere: public Figure
{
protected:
    double r;
public:
    Sphere(string, double);
    virtual string get_type();
    double get_square();
    double get_volume();
    friend istream& operator>>(istream&, Figure*&);
 };
