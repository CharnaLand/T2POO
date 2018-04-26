#include "Matr_oar.h"



class Matrice_patratica: public Matrice
{
    int dim;
public:
    Matrice_patratica(int x);
    Matrice_patratica(const Matrice_patratica& m);
    ~Matrice_patratica();
    Matrice_patratica operator+(Matrice_patratica&);
    Matrice_patratica& operator*(int);
    Matrice_patratica& operator*=(int);
    Matrice_patratica& operator=(const Matrice_patratica&);
    Complex* operator[] (int i);
    ///FRIEND
    friend ifstream& operator>> (ifstream&,Matrice_patratica&);
    friend istream& operator>> (istream&,Matrice_patratica&);
    friend ostream& operator<< (ostream&, Matrice_patratica&);
    ///STREAM
    void in_stream (istream& in);
    void f_stream (ifstream& fin);
    void out_stream (ostream& out);
    ///ALTELE
    Complex DETERMINANT ();
    int trio_sup();
    int trio_inf();
    int triunghiulara();
    int diagonala();
};


Matrice_patratica::Matrice_patratica(int x=0):Matrice(x,x), dim(x)
{
}

Matrice_patratica::Matrice_patratica(const Matrice_patratica& m):Matrice(m.dim,m.dim), dim(m.dim)
{
for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++) v[i][j]=m.v[i][j];
}

Matrice_patratica::~Matrice_patratica()
{
for(int i=0;i<dim;i++) delete[] v[i];
delete[] v;
dim=0;
v=NULL;
}

///STREAM

void Matrice_patratica::in_stream (istream& in)
{
    in>>*(Matrice_patratica*)this;
}

void Matrice_patratica::f_stream (ifstream& fin)
{
    fin>>*this;
}

void Matrice_patratica::out_stream (ostream& out)
{
    out<<*this;
}

///FRIEND

ifstream& operator>> (ifstream& fin,Matrice_patratica& mat)
{
    fin>>mat.dim;
    mat.v=new Complex*[mat.dim];
    for(int i=0;i<mat.dim;i++) mat.v[i]=new Complex[mat.dim];
    for(int i=0;i<mat.dim;i++)
        for(int j=0;j<mat.dim;j++) fin>>mat.v[i][j];
    return fin;
}

istream& operator>> (istream& in,Matrice_patratica& mat)
{
    cout<<"Introduceti DIMENSIUNEA matricii patratice: ";
    in>>mat.dim;
    mat.v=new Complex*[mat.dim];
    cout<<"Introduceti cate "<<mat.dim<<" ELEMENTE pentru fiecare dintre cele "<<mat.dim<<" LINII:\n";
    for(int i=0;i<mat.dim;i++) mat.v[i]=new Complex[mat.dim];
    for(int i=0;i<mat.dim;i++)
        for(int j=0;j<mat.dim;j++) in>>mat.v[i][j];
    return in;
}

ostream& operator<< (ostream& out, Matrice_patratica& mat)
{

    for(int i=0;i<mat.dim;i++)
    {
        for(int j=0;j<mat.dim;j++) out<<mat.v[i][j];
        out<<"\n";
    }
cout<<"\n";
return out;
}

///OPERATORI

Matrice_patratica Matrice_patratica::operator+(Matrice_patratica& z)
{
    Matrice_patratica sum(max(dim,z.dim));
    int dc=min(dim,z.dim);   ///DIMENISUNE COMUNA

    for(int i=0;i<dc;i++)
    {
        for(int j=0;j<dc;j++)
            sum.v[i][j]=v[i][j]+z.v[i][j];

        for(int j=dc;j<sum.dim;j++)
        {
            if(dim>z.dim) sum.v[i][j]=v[i][j];
            if(dim<z.dim) sum.v[i][j]=z.v[i][j];
        }
    }
    for(int i=dc;i<sum.dim;i++)
    {
            if(dim>z.dim) for(int j=0;j<dim;j++) sum.v[i][j]=v[i][j];
            if(dim<z.dim) for(int j=0;j<z.dim;j++) sum.v[i][j]=z.v[i][j];
    }
return sum;
}

Matrice_patratica& Matrice_patratica::operator=(const Matrice_patratica& m)
{
dim=m.dim;
v=new Complex*[dim];
for(int i=0;i<dim;i++)
{
    v[i]=new Complex[dim];
    for(int j=0;j<dim;j++) v[i][j]=m.v[i][j];
}
}


Matrice_patratica& Matrice_patratica::operator*(int x)
{
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++) v[i][j]*=x;
}

Matrice_patratica& Matrice_patratica::operator*=(int x)
{
    *this = *this * x;
    return *this;
}

Complex* Matrice_patratica::operator[](int i)
{
    return v[i];
}

///DIAGONALA SI TRIUNGHILARA

int Matrice_patratica::trio_sup()
{
Complex ZERO(0,0);
    for(int i=1;i<dim;i++)
        for(int j=0;j<i-1;j++)
            if(v[i][j]!=ZERO) return 0;
    return 1;
}

int Matrice_patratica::trio_inf()
{
Complex ZERO(0,0);
    for(int i=0;i<dim-1;i++)
        for(int j=i+1;j<dim;j++)
            if(v[i][j]!=ZERO) return 0;
    return 1;
}

int Matrice_patratica::triunghiulara()
{
    int s=trio_sup(), i=trio_inf();
    if(s+i==1) return 1;
    return 0;
}

int Matrice_patratica::diagonala()
{
    if(trio_inf() && trio_sup()) return 1;
    return 0;
}


///DETERMINANT

struct Vect
{
    int* sol;
    int n;
};
struct Matr
{
    Matrice_patratica M;
    Complex det;
};

int sign (Vect* Vt)
{
int ala=1;
    for(int  i=1;i<Vt->n;i++)
        for(int j=i+1;j<=Vt->n;j++)
        if(i!=j) ala*=(Vt->sol[j]-Vt->sol[i]);
if(ala>0) return 1;
else return -1;
}

void afiss(Vect* Vt)///DE FACUT CU MANA DE ADIO
{
    for(int i=1;i<=Vt->n;i++)
        cout<<Vt->sol[i]<<" ";
    cout<<" -> "<<sign(Vt)<<"\n";
}

void adunn (Vect* Vt, Matr* Mt)
{
Complex x(Mt->M[0][Vt->sol[1]-1]);
int si=sign(Vt);
x*=si;

    for(int i=2;i<=Vt->n;i++) x*=Mt->M[i-1][Vt->sol[i]-1];


Mt->det+=x;
}

int okk(int* sol,int k)
{
    for(int i=1;i<k;i++)
        if(sol[i]==sol[k]) return 0;
    return 1;
}

void backk (Vect* Vt, Matr* Mt, int k=1)
{
if(k==Vt->n+1) adunn(Vt,Mt);
else
    for(int i=1;i<=Vt->n;i++)
    {
        Vt->sol[k]=i;
        if(okk(Vt->sol,k)) backk(Vt,Mt,k+1);
    }
}

Complex Matrice_patratica::DETERMINANT()
{
Vect Vt; Matr Mt;
Vt.n=dim;
Vt.sol=new int[Vt.n+1];
Mt.M=*this;
Mt.det(0,0);

backk(&Vt,&Mt);

return Mt.det;
}
