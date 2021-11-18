#include <iostream>
using namespace std;


// Класс - это описание какого то типа данных
// class A
// {
// public:
//     int data;
//     void show_data()
//     {
//         cout << data << endl;
//     }
// };

// Экземпляр класса (переменная класса)
//object

// class Human
// {
// public:
//     string name;
//     int age;
//     Human(string _name, int _age):name(_name),age(_age){}
//     void show()
//     {
//         cout << name << " " << age << endl;
//     }
// };   
                    

class Complex
{
public:
    double re;
    double im;
    // Complex(){
    //     re = 0;
    //     im = 0;
    // }
    Complex(double _re = 0, double _im = 0)
    {
        re = _re;
        im = _im;
    }
    void show()
    {
        cout << re << " + i" << im << endl;
    }
};

int main()
{

    Complex z;
    Complex z1(3,4);
    Complex z2(5);
    z.show();
    z1.show();
    z2.show();
    // A a;
    // a.data = 4;
    // a.show_data();

    // A aa;
    // aa.data = 3;
    // aa.show_data()

    // Human jack;
    // jack.name = "Jake Black";
    // jack.age = 20;
    // jack.show();


    // Human jack;
    // jack.name = "Jake Black";
    // jack.age = 20;

    // Human tom;
    // tom.name = "Tom Red";
    // tom.age = 25;

    // Human alex;
    // alex.name = "Alex Green";
    // alex.age = 45;

    // Human people[]{Human("Jake Black",20), Human("Tom Red",25), Human("Alex Green",45)};
    // // for (int i=0; i <3; i++)
    // {
    //     people[i].show();
    // }
    
    // for(auto person : people)//Диапозонный цикл
    // {
    //     person.show();
    // }

    // auto max_age_person = people[0];

    // for(auto person : people)//Диапозонный цикл
    // {
    //     if(max_age_person.age < person.age)
    //     {
    //         max_age_person = person;
    //     }
    // }
    // max_age_person.show();
}