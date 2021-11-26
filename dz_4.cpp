// Создайте иерархию классов на основе класса Фигура. 
// Должны быть описаны классы Квадрат, Прямоугольник, Треугольник, Круг, Куб, Шар.
// --
// Реализовать конструкторы, 
// --
// Методы, выводящие информацию о фигуре(название и тип), 
// --
// Методы, считающие площадь, периметр и объем(где он есть)

#include <iostream>
#include <string>
using namespace std;

class Figure
{
protected:
  string name;
  string type;
public:
  Figure(string name, string type)
  {
    this->name = name;
    this->type = type;
  }
  string get_name()
  {
    return "Name of figure is: " + name;
  }
  string get_type()
  {
    return "Type of figure is: " + type;;
  }
   void show()
   {
     cout << get_name() << " " << get_type() << endl;
   }
};

class Square: public Figure
{
protected:
    int a;
public:
  Square(string name, string type, int a):Figure(name, type)
  {
      //this -> name = name;
      //this -> type = type;
      this -> a = a;
  }
    int get_square()
    {
        return a * a;
    }
    int get_perimeter()
    {
        return 4 * a;
    }
};

class Rectangle: public Square
{
private:
    int b;
public:
  Rectangle(string name, string type, int a, int b):Square(name, type, a)
  {
      this -> b = b;
  }
    int get_square()
    {
        return a * b;
    }
    int get_perimeter()
    {
        return 2*a + 2*b;
    }
};


int main()
{
    Square Kvadrat("Первая фигура", "Квадрат", 3);
    cout << Kvadrat.get_square() << endl;
    cout << Kvadrat.get_perimeter() << endl;
    Kvadrat.show();

    Rectangle Pr("Вторая фигура", "Прямоугольник", 3, 2);
    cout << Pr.get_square() << endl;
    cout << Pr.get_perimeter() << endl;
    Pr.show();


//   int marks[3]{ 5,4,5 };
//   Student s("Jack", 23, marks, 3);
//   Teacher t("Tom", 43, 3);
//   //cout << s.get_name() << " " << s.get_age() << endl;
//   //s.get_marks();
//   //cout << t.get_name() << " " << t.get_age() <<" "<< t.get_number_of_publications()<<endl;
//   s.is_good();
//   t.is_good();
}






// class Human
// {
// protected:
//   string name;
//   float age;
// public:
//   Human(string name, float age)
//   {
//     this->name = name;
//     this->age = age;
//   }
//   string get_name()
//   {
//     return "My name is: " + name;
//   }
//   float get_age()
//   {
//     return age;
//   }
//   void is_good()
//   {
//     cout << "My name is: " << name << ". " << "My age is: " << age << endl;
//   }
// };
// class Student: public Human
// {
// private:
//   static const int max_size = 10;
//   int marks[max_size];
//   int number_of_marks = 0;
// public:
//   Student(string name, float age, int marks[], int n):Human(name, age)
//   {
//     for (int i = 0; i < n; i++)
//     {
//       this->marks[i] = marks[i];
//     }
//     number_of_marks = n;
//   }
//   void get_marks()
//   {
//     for (int i = 0; i < number_of_marks; i++)
//     {
//       cout << marks[i] << " ";
//       cout << endl;
//     }
//   }
//   void is_good()
//   {
//     Human::is_good();
//     float res = 0;
//     for (int i = 0; i < number_of_marks; i++)
//     {
//       res += marks[i];
//     }
//     res /= number_of_marks;

//     if (res >= 4)
//     {
//       cout << "I'm a good student" << endl;
//     }
//     else
//     {
//       cout << "I'm a bad student" << endl;
//     }
//   }
// };
// class Teacher : public Human
// {
// private:
//   int number_of_publications;
// public:
//   Teacher(string name, float age, int number_of_publications):Human(name, age)
//   {
//     this->number_of_publications = number_of_publications;
//   }
//   int get_number_of_publications()
//   {
//     return number_of_publications;
//   }
//   void is_good()
//   {
//     Human::is_good();
//     if (number_of_publications >= 5)
//     {
//       cout << "I'm a good teacher" << endl;
//     }
//     else
//     {
//       cout << "I'm a bad teacher" << endl;
//     }
//   }
// };
// int main()
// {
//   int marks[3]{ 5,4,5 };
//   Student s("Jack", 23, marks, 3);
//   Teacher t("Tom", 43, 3);
//   //cout << s.get_name() << " " << s.get_age() << endl;
//   //s.get_marks();
//   //cout << t.get_name() << " " << t.get_age() <<" "<< t.get_number_of_publications()<<endl;
//   s.is_good();
//   t.is_good();
// }