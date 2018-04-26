#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


class Complex
{
    float re,im;
 public:
    Complex();
    Complex(Complex&);
    Complex(float,float);
    ~Complex();
    ///OPERATORI
    Complex operator+ (const Complex&);
    Complex operator* (int);
    Complex operator* (const Complex&);
    Complex operator/ (const Complex&);
    Complex operator/ (int);
    operator+= (const Complex&);
    operator*= (int);
    operator*= (const Complex&);
    operator /= (int);
    operator= (const Complex&);
    bool operator== (const Complex&);
    bool operator!= (const Complex&);
    Complex& operator() (float r, float i){re=r;im=i;}
        ///SET

        ///GET

        ///FRIEND
    friend ifstream& operator>> (ifstream&,Complex&);
    friend istream& operator>> (istream&,Complex&);
    friend ostream& operator<< (ostream&,Complex&);
        ///ALTELE
    float modul(){return (float)sqrt(re*re+im*im);}
};



Complex::Complex()
{
re=im=0;
}

Complex::Complex(float r, float i)
{
    re=r;
    im=i;
}

Complex::Complex(Complex& z)
{
    re=z.re;
    im=z.im;
}

Complex::~Complex()
{
re=im=0;
}

Complex Complex::operator+(const Complex& z)
{
Complex sum;
    sum.re=re+z.re;
    sum.im=im+z.im;
return sum;
}

Complex::operator+= (const Complex& z)
{
    *this=*this+z;
}

Complex Complex::operator* (int x)
{
Complex rez;
    rez.re=re*x;
    rez.im=im*x;
return rez;
}

Complex Complex::operator*(const Complex& z)
{
Complex rez;
    rez.re=re*z.re-im*z.im;
    rez.im=re*z.im+z.re*im;

return rez;
}

Complex::operator=(const Complex& z)
{
re=z.re;
im=z.im;

}

Complex::operator*= (int x)
{
    *this= *this*x;
}

Complex::operator*= (const Complex& z)
{
    *this = *this * z;
}

bool Complex::operator== (const Complex& z)
{
    if(re==z.re && im==z.im) return 1;
    return 0;
}

bool Complex::operator!= (const Complex& z)
{
    if(re==z.re && im==z.im) return 0;
    return 1;
}

Complex Complex::operator/ (int i)
{
Complex rez(re,im);
        rez.re/=i;
        rez.im/=i;
return rez;
}

Complex::operator /= (int i)
{
    *this = *this / i;
}

Complex Complex::operator/ (const Complex& z)
{
Complex rez, zz(z.re,-z.im);
    zz*=z;
    float sub=zz.re;
    zz(z.re,-z.im);
    rez=*this * zz;
    rez/=sub;
return rez;
}


ifstream& operator>> (ifstream& fin,Complex& z)
{
fin>>z.re>>z.im;
return fin;
}

istream& operator>> (istream& in,Complex& z)
{
cout<<"Re:";
in>>z.re;
cout<<"Im:";
in>>z.im;
return in;
}

ostream& operator<< (ostream& out, Complex& z)///FARA \n
{
if(z.re==z.im && z.im==0) cout<<"0";
else
{

    if(z.re) out<<z.re;

    if(z.im==1) out<<"+i";
    else
    {
    if(z.im==-1) out<<"-i";
    else
        {
            if(z.im>0)
                {if(z.re) out<<"+";
                out<<z.im<<"i";}
            else if(z.im<0)out<<z.im<<"i";
        }
    }
}
out<<" ";
return out;
}
