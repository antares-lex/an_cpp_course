// Для прошлого задания
// (

//     Создайте иерархию классов на основе класса Фигура. 
//     Должны быть описаны классы Квадрат, Прямоугольник, Треугольник, Круг, Куб, Шар.
//     --Реализовать конструкторы, 
//     --Методы, выводящие информацию о фигуре(название и тип), 
//     --Методы, считающие площадь, периметр и объем(где он есть)
// )
// Добавьте следующие возможности:
// --Базовый класс должен быть абстрактным
// --Создать динамический массив на n элементов(вводится пользователем) и добавить в него набор различных фигур случайным образом
// --Найти фигуру с самой большой площадью. Если таких фигур несколько вывести все
// --Перегрузить операторы ввода и вывода для фигур
// --Результат вывести в файл
// --Классы разбить по файлам

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Figure
{
protected:
    string name;
    //string type;// = "Figure";
public:
    Figure(string name)//, string type)
    {
        this->name = name;
    }
    string get_name()
    {
        return name;
    }
    virtual string get_type() = 0;
    void show()
    {
        cout << "Name of figure is: " + get_name() << " Type of figure is: " << get_type() << endl;
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
  }
  string get_type()
  {
    return "Square";  
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
  }
    string get_type()
    {
        return "Rectangle";  
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
  }
    string get_type()
    {
        return "Triangle";  
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
  }
    string get_type()
    {
        return "Circle";  
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
  Cube(string name, double a):Square(name, a){}
    string get_type()
    {
        return "Cube";  
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
  Sphere(string name, double r):Circle(name, r){}
    string get_type()
    {
        return "Sphere";  
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



int main()
{
    //Figure f("dsf");

    Square Kvadrat("Первая фигура", 20);
    cout << Kvadrat.get_square() << endl;
    cout << Kvadrat.get_perimeter() << endl;
    Kvadrat.show();

    Rectangle Pr("Вторая фигура", 3, 2);
    cout << Pr.get_square() << endl;
    cout << Pr.get_perimeter() << endl;
    Pr.show();

    Triangle Tr("Третья фигура", 1, 1, 1);
    cout << Tr.get_square() << endl;
    cout << Tr.get_perimeter() << endl;
    Tr.show();

    Circle Kr("Четвертая фигура", 1);
    cout << Kr.get_square() << endl;
    cout << Kr.get_perimeter() << endl;
    Kr.show();

    Cube Cub("Пятая фигура", 2);
    cout << Cub.get_square() << endl;
    cout << Cub.get_perimeter() << endl;
    cout << Cub.get_volume() << endl;
    Cub.show();

    Sphere Shar("Шестая фигура", 1);
    cout << Shar.get_square() << endl;
    cout << Shar.get_volume() << endl;
    Shar.show();


//   int marks[3]{ 5,4,5 };
//   Student s("Jack", 23, marks, 3);
//   Teacher t("Tom", 43, 3);
//   //cout << s.get_name() << " " << s.get_age() << endl;
//   //s.get_marks();
//   //cout << t.get_name() << " " << t.get_age() <<" "<< t.get_number_of_publications()<<endl;
//   s.is_good();
//   t.is_good();
}

