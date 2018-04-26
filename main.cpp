#include "Matr_patr.h"
using namespace std;

/**
- Complex(float re,im)
- Matrice( Complex **v)
- Matrice_oarecare (int lin, int col) : Matrice
- Matrice_patratica (int dim): Matrice
*/


int main()
{
ifstream f ("date.in");
Matrice *oare, *patr;
oare=new Matrice_oarecare;
patr=new Matrice_patratica;
f>>*oare>>*patr;

Matrice_oarecare& uno=*((Matrice_oarecare*)oare);

Matrice_patratica& dos=*((Matrice_patratica*)patr);

Matrice_oarecare ceva(uno), cevaa(*((Matrice_oarecare*)oare));
Matrice_patratica altcv(dos), altcvv(*((Matrice_patratica*)patr));
cout<<uno<<ceva<<cevaa;
cout<<dos<<altcv<<altcvv;

/*
int n;
f>>n;
Matrice* v[n];

for(int i=0;i<n;i++)
    {
    v[i]=new Matrice_patratica;
    f>>*v[i];
    }
Complex Det;
for(int i=0;i<n;i++)
    {
        cout<<*v[i];
        Det=v[i]->DETERMINANT();
        cout<<"Determinantul este: "<<Det<<"\n";
        cout<<"E sup: "<<v[i]->trio_sup()<<"\n";
        cout<<"E inf: "<<v[i]->trio_inf()<<"\n";
        cout<<"E triug: "<<v[i]->triunghiulara()<<"\n";
        cout<<"E diag: "<<v[i]->diagonala()<<"\n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
*/
f.close();
return 0;
}
