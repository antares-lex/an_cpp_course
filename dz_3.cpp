// 1) Модифициоровать класс для работы с дробными числами.
// Он должен содержать:
// -Числитель +
// -Знаменатель +
// -Конструктор, + 
//  Деструктор  +
/* -Перегруженнные операторы для сложения, + 
                                вычитания, +
                                умножения, +
                                деления, +
                                сравнения дробных чисел, +
// операторов   +=, +
                -=, +
                *=, +
                /=  +                     */



// 2) Реализовать односвязный список, обладающим следующим функционалом
// -Добавление элементов в конец списка
// -Добавление элементов в начало списка
// -Вывод элементов списка
// -Получение количества элементов списка
// -Вставление элемента на указанную позицию
// -Удаление всех элементов
// -Удаление первого элемента списка
// -Удаление последнего элемента списка
// -Удаление элемента на указанной позиции
// -Удаление элементов в диапозоне между двумя указанными позициями

#include <iostream>
#include <string>
using namespace std;

class fract_num
{
private:
    int num; //числитель
    int denom; //знаменатель
public:
    fract_num(int _num = 0, int _denom = 1)
    {
        set_num(_num);
        set_denom(_denom);
    }
    ~fract_num()
    {
        cout << "destructor" << endl;  
    }
    void set_num(int _num)
    {
        num = _num;
    }
    int get_num()
    {
        return num;
    }
    void set_denom(int _denom)
    {
        denom = _denom;
    }
    int get_denom()
    {
        return denom;
    }
    void show()
    {
        cout << "Числитель: " << num << "  Знаменатель: " << denom << endl;
    }  
    int nod(int m, int n) 
    {
        while (n > 0) 
        {   
            int res = m % n;
            m = n;
            n = res;
        }
        return m;
    }    
    fract_num operator+(fract_num a) //Сложение
    {
        int num_2 = num * a.denom + a.num * denom;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        return fract_num(num_2/nod_1, denom_2/nod_1);
                            
    }
    fract_num operator-(fract_num a)//Вычитание
    {
        int num_2 = num * a.denom - a.num * denom;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        return fract_num(num_2/nod_1, denom_2/nod_1);
    }
    fract_num operator*(fract_num a) //Умножение
    {
        int num_2 = num * a.num;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        return fract_num(num_2/nod_1, denom_2/nod_1);
    }
    fract_num operator/(fract_num a) //Деление
    {
        int num_2 = num * a.denom;
        int denom_2 = denom * a.num;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        return fract_num(num_2/nod_1, denom_2/nod_1);
    }
    bool operator==(fract_num a) //Сравнение
    {
        int nod_1 = nod(abs(num), abs(denom));
        int nod_2 = nod(abs(a.num), abs(a.denom));
        return num/nod_1 == a.num/nod_2 && denom/nod_1 == a.denom/nod_2;
    }
    fract_num& operator+=(fract_num a)
    {
        int num_2 = num * a.denom + a.num * denom;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        num = num_2/nod_1;
        denom = denom_2/nod_1;
        return *this;
    }
    fract_num& operator-=(fract_num a)
    {
        int num_2 = num * a.denom - a.num * denom;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        num = num_2/nod_1;
        denom = denom_2/nod_1;
        return *this;
    }
    fract_num& operator*=(fract_num a)
    {
        int num_2 = num * a.num;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        num = num_2/nod_1;
        denom = denom_2/nod_1;
        return *this;
    }
    fract_num& operator/=(fract_num a)
    {
        int num_2 = num * a.denom;
        int denom_2 = denom * a.num;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        num = num_2/nod_1;
        denom = denom_2/nod_1;
        return *this;
    }



//    Complex& operator+=(Complex c)
//     {
//         re += c.re;
//         im += c.im;
//         return *this;
//     }



};

int main()
{

    fract_num drob1(4,2);
    fract_num drob2(8,4);

    drob2 /= drob1; 
    drob2.show(); 


    // if (drob1 == drob2)
    // {
    //     cout << "equal" << endl;
    // }
    // else
    // {
    //     cout << "not_equal" << endl;
    // };

    // fract_num drob3 = drob1 + drob2;
    // drob3.show();

    // fract_num drob4 = drob1 - drob2;
    // drob4.show();
    
    // fract_num drob5 = drob1 * drob2;
    // drob5.show();

    // fract_num drob6 = drob1 / drob2;
    // drob6.show();
    //int mod = 4 % 2;

    //drob3.show();   
    
    //cout << drob3.nod(drob3.get_num(),drob3.get_denom()) << endl;

}