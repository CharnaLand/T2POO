<<<<<<< HEAD
#include "CLASE.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/**
- Complex(float re,im)
- Matrice( Complex **v)
- Matrice_oarecare (int lin, int col) : Matrice
- Matrice_patratica (int dim): Matrice
*/

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

int main()
{
ifstream f ("date.in");

Matrice **v;
v=new Matrice*[3];
for(int i=0;i<3;i++)
    {
    v[i]=new Matrice_patratica;
    f>>*v[i];
    }

for(int i=0;i<3;i++)
    cout<<*v[i];

f.close();
return 0;
}
=======
#include "CLASE.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/**
- Complex(float re,im)
- Matrice( Complex **v)
- Matrice_oarecare (int lin, int col) : Matrice
- Matrice_patratica (int dim): Matrice
*/

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

int main()
{
ifstream f ("date.in");

Matrice **v;
v=new Matrice*[3];
for(int i=0;i<3;i++)
    {
    v[i]=new Matrice_patratica;
    f>>*v[i];
    //f[i]->citire();
    }

for(int i=0;i<3;i++)
    cout<<*v[i];

f.close();
return 0;
}
>>>>>>> 79494b10b59ac5118a992edabac4602b8755b8a4
