#include <iostream>
#include<string>
using namespace std;
/*class Human
{
    // Инкапсуляция есть сокрытие данных
    // Инкапсуляция можно интерпритировать как
    // положить в какую то КАПСУЛУ, то есть закрыть данные
private: // public, private - модификаторы доступа
    string name;
    int age;
public:
    Human(string _name, int _age)
    {
        set_age(_age);
        set_name(_name);
    }
    void show()
    {
        cout << name << " " << age << endl;
    }
    
    int get_age()
    {
        return age;
    }
    
    void set_age(int _age)
    {
       if(_age >= 0)
        {
            age = _age;
        }
        else
        {
            age = 0;
        } 
    }

    string get_name()
    {
        return name;
    }

    void set_name(string _name)
    {
        name = _name;
    }
    
};

int main()
{
  Human jack("Jack", 20);
  //jack.age = 350;
  //jack.show();
  cout << jack.get_name() << endl;  
  jack.set_age(-20);
  jack.show();
}
*/


class Complex
{
private:
    double re, im;
public:
    Complex(double _re = 0, double _im = 0)
    {
        set_re(_re);
        set_im(_im);
    }
    double get_re()
    {
        return re;
    }
    
    void set_re(double _re)
    {
        re = _re;
    }

    double get_im()
    {
        return im;
    }
    
    void set_im(double _im)
    {
        im = _im;
    }

    string show()
    {
        return to_string(re) + " + " + to_string(im) + " i";
    }

    Complex add(Complex c)
    {
        return Complex(re + c.re, im + c.im);
    }

    Complex sub(Complex c)
    {
        Complex res;
        res.set_re(re - c.re);
        res.set_im(im - c.im);
        return res;
    }

    Complex mul(Complex c)
    {
        
        //(a+ib)*(x+iy) = ax + i ay + i bx - by





        return Complex(re*c.re - im * c.im, re*c.im+im*c.re);
        
        Complex res;
        res.set_re(re - c.re);
        res.set_im(im - c.im);
        return res;
    }


    bool is_equal_to(Complex c)
    {
        return re == c.re && im == c.im;
    }

    bool is_not_equal_to(Complex c)
    {
        return !(re == c.re && im == c.im);
    }

};

int main()
{
    Complex z1(2, 3);
    Complex z2(2, 3);

    if (z1.is_not_equal_to(z2))
    {
        cout << "not equal" << endl;
    }
    else
    {
        cout << "equal" << endl;
    }
    //Complex z3(1, 1);
    
    //Complex z3 = z1.mul(z2);


    // Complex z1(2, 3);
    // Complex z2(6, 12);
    // //Complex z3 = z1.add(z2);
    // Complex z3 = z2.sub(z1);
    
    // if (z1.is_equal_to(z2))
    // {
    //     cout << "equal" << endl;
    // }
    // else
    // {
    //     cout << "not_equal" << endl;
    // }

    
    //cout << z1.is_equal_to(z2) << endl;

    // Complex z(2, 3);
    // z.set_re(7);
    // cout << z.show();
};