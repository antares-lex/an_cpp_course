#include <iostream>
#include<string>
using namespace std;


int main()
{
    //auto - автоопределение типа переменной, auto c = 10 - тип integer
    // auto c = 10;

    // int m[] = {2, 3, 4, 5, 6};
    // // for(auto item: m)
    // // {
    // //     cout << item << endl;
    // // }

    // for(auto &item: m) // игра с ссылками, не создается копий и присваивается значение к массиву
    // {
    //     item *= 2;
    // }
    // cout << m[0] << endl;

    
    // std::string name;
    // name = "Tom";
    // cout << name << endl;


    // string name;
    // getline(cin, name);
    // //cin >> name;
    // cout << name;


    // int age;
    // cin >> age; //age\n  - здесь объясняется почему после вводу cin не работает getline
    // cin.ignore(32767, '\n'); // cin имеет после введенного значения контрукцию \n, что мешает дальше работать вводу
    // string name;            // по этому мы игнорируем этот набор символов предыдущей командой
    // //cin >> name;
    // getline(cin, name);
    // cout << "name: " << name << " age: " << age << endl;

    string a = "hello";
    string b = "world";
    string c = a + b;
    cout << c << " " << c.length();


}