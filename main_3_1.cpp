#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Перегрузка операторов - это такая штука, чтоб делать "красиво" :)
// например вместо d = a.add(b).add(c)      d = a + b + c
// специальный синтаксис operator+
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
    double module_of_number()
    {
        return sqrt(pow(re,2)+pow(im,2));
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
    Complex operator+(Complex c)
    {
        return Complex(re + c.re, im + c.im);
    }
    Complex operator-(Complex c)
    {
        Complex res;
        res.set_re(re - c.re);
        res.set_im(im - c.im);
        return res;
    }
    Complex operator*(Complex c)
    {
        return Complex(re*c.re - im * c.im, re*c.im+im*c.re);   
        Complex res;
        res.set_re(re - c.re);
        res.set_im(im - c.im);
        return res;
    }
    bool operator==(Complex c)
    {
        return re == c.re && im == c.im;
    }
    bool operator!=(Complex c)
    {
        return !(re == c.re && im == c.im);
    }
    bool operator>(Complex c)
    {
        return module_of_number() > c.module_of_number();
    }
    bool operator>=(Complex c)
    {
        return module_of_number() >= c.module_of_number();
    }
    bool operator<(Complex c)
    {
        return module_of_number() < c.module_of_number();
    }
    bool operator<=(Complex c)
    {
        return module_of_number() <= c.module_of_number();
    }
    Complex& operator+=(Complex c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }


};

// int x = 0;
// int& f()
// {
//     return x;
// }

class SafeArray
{
    private:
        const static int size = 10; // static - константа определена для класса, а не для объекта этого класса?
        int arr[size];
    public:
    void set(int index, int value)
    {
        if(index<0 || index >= size)
        {
            cout << "Error. Index is out of a range"<< endl;
        }
        arr[index] = value;
    }
    int get(int index)
    {
        if(index<0 || index >= size)
        {
            cout << "Error. Index is out of range"<< endl;
            exit(1);
        }
        return arr[index];
    }
    int& operator[](int index)
    {
        if(index<0 || index >= size)
            {
                cout << "Error. Index is out of range"<< endl;
                exit(1);
            }
            return arr[index];   
    }

};

class ExampleEquality
{
// private:
//     char* data;
//     int lenght;
public:
    char* data;
    int lenght;

    ExampleEquality()
    {

    }
    ExampleEquality(const char * _data, int _lenght)
    {
        data = new char[lenght];
        for(int i=0; i < _lenght; i++)
        {
            data[i] = _data[i];
        }
        lenght = _lenght;
    }
    ~ExampleEquality() // Диструктор для высвобождения памяти
    {
        delete[] data;
    }
    ExampleEquality& operator=(ExampleEquality& c)
    {
        data = new char[c.lenght];
        for(int i=0; i < c.lenght; i++)
        {
            data[i] = c.data[i];
        }

        lenght = c.lenght;

        return *this;

    }
    void show()
    {
        cout << data << endl;
    }
};


int main()
{
    ExampleEquality ex("Jack Black", 11);
    ExampleEquality ex_copy;
    ex_copy = ex;
    ex.data[1] = 'o';
    ex_copy.show();

    // Complex a(2,3);
    // Complex b;
    // b = a;
    // cout << b.show(); 

    // f() = 7;
    // cout << x << endl;


    // SafeArray s;
    // s[9] = 4;
    // cout << s[3];
    //s.set(3,5);
    //cout << s.get(3);




    // Complex a(2,3);
     //Complex b(1,3);
//     // Complex c(6,7);
//     // Complex d;

//     // d = a + b + c; // это выражение выглядит как d = a.operator+(b).operator+(c)
    
    
//    // cout << d.show() << endl;

//    cout << (a == b) << endl;

    // a += b;

}