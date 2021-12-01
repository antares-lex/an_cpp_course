// Для ручного ввода выбрана Фигура Square, 
// остальные данные для случайных фигур генерируются также случайно

#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;

int main()
{
    int max_number_shapes = 0;
    cout << "Введите количество фигур: "; 
    cin >> max_number_shapes;
    Figure* shapes[100];
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

}