// Для прошлого задания
// (

//     Создайте иерархию классов на основе класса Фигура. 
//     Должны быть описаны классы Квадрат, Прямоугольник, Треугольник, Круг, Куб, Шар.
//     --Реализовать конструкторы, 
//     --Методы, выводящие информацию о фигуре(название и тип), 
//     --Методы, считающие площадь, периметр и объем(где он есть)
// )
// Добавьте следующие возможности:
// --Базовый класс должен быть абстрактным +
// --Создать динамический массив на n элементов(вводится пользователем) и добавить в него набор различных фигур случайным образом +
// --Найти фигуру с самой большой площадью. Если таких фигур несколько вывести все +
// --Перегрузить операторы ввода и вывода для фигур + 
// --Результат вывести в файл +
// --Классы разбить по файлам

// Для ручного ввода выбрана Фигура Square

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

class Figure
{
protected:
    string name;
public:
    Figure(string name)
    {
        this->name = name;
    }
    string get_name()
    {
        return name;
    }
    virtual double get_square() = 0;
    virtual string get_type() = 0;
    void show()
    {
        cout << "Name of figure is: " + get_name() << " Type of figure is: " << get_type() << endl;
    }
    friend ostream& operator<<(ostream&, Figure*&);
    friend istream& operator>>(istream&, Figure*&);
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
  virtual string get_type()
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
      friend istream& operator>>(istream&, Square*&);
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
  void set_name(string _name, double _a)
  {
    name = _name;
    a = _a;
  }
  virtual string get_type()
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
  friend istream& operator>>(istream&, Rectangle*&);
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
    virtual string get_type()
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
  friend istream& operator>>(istream&, Triangle*&);
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
    virtual string get_type()
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
  friend istream& operator>>(istream&, Circle*&);
};
class Cube: public Square
{
public:
  Cube(string name, double a):Square(name, a){}
    virtual string get_type()
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
  friend istream& operator>>(istream&, Cube*&);
};
class Sphere: public Circle
{
public:
  Sphere(string name, double r):Circle(name, r){}
     virtual string get_type()
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
  friend istream& operator>>(istream&, Sphere*&);
 };

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

int main()
{
    int max_number_shapes = 0;
    cout << "Введите количество фигур: "; 
    cin >> max_number_shapes;
    Figure* shapes[max_number_shapes];
    int current_number = 0;
    const int number_of_names = 7;
    string names[number_of_names]{ "Red", "Black", "Blue", "Green", "White", "Yellow", "Grey"};
    string types[]{ "Square", "Rectangle", "Triangle",  "Circle", "Cube", "Sphere"};
    double max_square = 0;
  
  for(int i= 0; i< max_number_shapes;i++)
  {
    int type = rand() % 6;
    current_number++;
    if (types[type] == "Square")
    {
      Square* shapes_1;
      shapes_1 = new Square(names[rand() % number_of_names], 2);// 1 + rand() % 9);
      cin >> shapes_1;
      shapes[current_number] = shapes_1;
    }
    else if (types[type] == "Rectangle")
    {
        shapes[current_number] = new Rectangle(names[rand() % number_of_names], 1 + rand() % 5, 1 + rand() % 5);
    } 
    else if (types[type] == "Triangle")
    {
        shapes[current_number] = new Triangle(names[rand() % number_of_names], 1 + rand() % 5, 1 + rand() % 5, 1 + rand() % 5);
    } 
    else if (types[type] == "Circle")
    {
        shapes[current_number] = new Circle(names[rand() % number_of_names], 1 + rand() % 5);
    } 
    else if (types[type] == "Cube")
    {
        shapes[current_number] = new Cube(names[rand() % number_of_names], 1 + rand() % 5);
    } 
    else if (types[type] == "Sphere")
    {
        shapes[current_number] = new Sphere(names[rand() % number_of_names], 1 + rand() % 5);
    } 
    cout <<  shapes[current_number];
    
  if (shapes[current_number]->get_square() > max_square)
    max_square = shapes[current_number]->get_square();
  }
  
  cout << "Максимальная площадь равна " << max_square << endl;
  cout << "______________________________________________"<< endl;
  current_number = 0;

  ofstream out("file.txt");
  
  out << "Фигура(ы) с самой большой площадью: " << endl;
  for(int i= 0; i< max_number_shapes;i++)
  {
    current_number++;
    if (max_square == shapes[current_number]->get_square())
    {
      out << shapes[current_number];
    };
  }
  out.close();

    //Figure f("dsf");

    // Square Kvadrat("Первая фигура", 20);
    // cout << Kvadrat.get_square() << endl;
    // cout << Kvadrat.get_perimeter() << endl;
    // Kvadrat.show();

    // Rectangle Pr("Вторая фигура", 3, 2);
    // cout << Pr.get_square() << endl;
    // cout << Pr.get_perimeter() << endl;
    // Pr.show();

    // Triangle Tr("Третья фигура", 1, 1, 1);
    // cout << Tr.get_square() << endl;
    // cout << Tr.get_perimeter() << endl;
    // Tr.show();

    // Circle Kr("Четвертая фигура", 1);
    // cout << Kr.get_square() << endl;
    // cout << Kr.get_perimeter() << endl;
    // Kr.show();

    // Cube Cub("Пятая фигура", 2);
    // cout << Cub.get_square() << endl;
    // cout << Cub.get_perimeter() << endl;
    // cout << Cub.get_volume() << endl;
    // Cub.show();

    // Sphere Shar("Шестая фигура", 1);
    // cout << Shar.get_square() << endl;
    // cout << Shar.get_volume() << endl;
    // Shar.show();

}

