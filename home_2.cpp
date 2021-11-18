// Реализовать класс для работы с дробными числами.
// Он должен содержать:
// -Числитель
// -Знаменатель
// -Конструктор
// -Методы для сложения, вычитания, умножения, деления, сравнения дробных чисел

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

    //Сложение
    
    fract_num add(fract_num a)
    {
        int num_2 = num * a.denom + a.num * denom;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        return fract_num(num_2/nod_1, denom_2/nod_1);
                            
    }

    //Вычитание
    
    fract_num sub(fract_num a)
    {
        int num_2 = num * a.denom - a.num * denom;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        return fract_num(num_2/nod_1, denom_2/nod_1);
    }

    //Умножение
    
    fract_num mul(fract_num a)
    {
        int num_2 = num * a.num;
        int denom_2 = denom * a.denom;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        return fract_num(num_2/nod_1, denom_2/nod_1);
    }

    //Деление
    
    fract_num div(fract_num a)
    {
        int num_2 = num * a.denom;
        int denom_2 = denom * a.num;
        int nod_1 = nod(abs(num_2), abs(denom_2));
        return fract_num(num_2/nod_1, denom_2/nod_1);
    }

    //Сравнение

    bool is_equal(fract_num a)
    {
        int nod_1 = nod(abs(num), abs(denom));
        int nod_2 = nod(abs(a.num), abs(a.denom));
        return num/nod_1 == a.num/nod_2 && denom/nod_1 == a.denom/nod_2;
    }

};

int main()
{
    fract_num drob1(4,2);
    fract_num drob2(8,4);

    if (drob1.is_equal(drob2))
    {
        cout << "equal" << endl;
    }
    else
    {
        cout << "not_equal" << endl;
    };

    fract_num drob3=drob1.add(drob2);
    drob3.show();

    fract_num drob4=drob1.sub(drob2);
    drob4.show();
    
    fract_num drob5=drob1.mul(drob2);
    drob5.show();

    fract_num drob6=drob1.div(drob2);
    drob6.show();
    //int mod = 4 % 2;

    //drob3.show();   
    
    //cout << drob3.nod(drob3.get_num(),drob3.get_denom()) << endl;

}
