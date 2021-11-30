#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;


const int max_number = 100;
const string file_name = "data.txt";
int generate_data(string file_name)
{
  const int number_of_names = 9;
  string names[number_of_names]{ "Jack", "Tom", "Ivan", "Peter", "Anna", "Kate", "Lisa", "Alex", "John" };
  string types[]{ "t", "s" };

  int number_of_people = rand() % (max_number + 1);
  ofstream out(file_name);

  for (int i = 0; i < number_of_people; i++)
  {
    int type = rand() % 2;
    out << types[type] << " " << names[rand() % number_of_names] << " " << rand() % 100 << " ";
    if (types[type] == "t")
    {
      out << rand() % 100 << endl;
    }
    else
    {
      out << rand() % 6 << endl;
    }
  }
  out.close();
  return number_of_people;
}

int main()
{
  int number_of_people = generate_data(file_name);
  Human* people[max_number];
  int current_number = 0;
  ifstream in(file_name);
  for(int i= 0; i< number_of_people;i++)
  {
    char choice;
    in >> choice;
    if (choice == 't')
    {
      string name;
      in >> name;

      int age;
      in >> age;

      int number_of_publications;
      in >> number_of_publications;

      people[current_number++] = new Teacher(name, age, number_of_publications);
    }
    else if (choice == 's')
    {
      string name;
      in >> name;

      int age;
      in >> age;

      float avg_mark;
      in >> avg_mark;

      people[current_number++] = new Student(name, age, avg_mark);
    }
    else
    {
      cout << "wrong input" << endl;
    }
  }
  in.close();
  for (int i = 0; i < current_number; i++)
  {
    if (people[i]->isGood())
    {
      cout << "This person is good" << endl;
      cout<<people[i];
      cout << "_______________" << endl;
    }
  }
}

    // © 2021 GitHub, Inc.

    // Terms
    // Privacy
    // Security
    // Status
    // Docs
    // Contact GitHub
    // Pricing
    // API
    // Training
    // Blog
    // About


