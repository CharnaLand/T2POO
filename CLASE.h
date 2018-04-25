
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

class Matrice
{
protected:
    Complex **v;
public:
    Matrice();
    Matrice(int l,int c);
    ~Matrice();
    virtual void in_stream (istream& in) {}
    virtual void f_stream (ifstream& fin) {}
    virtual void out_stream (ostream& out) {}
    ///FRIEND
    friend ifstream& operator>> (ifstream&,Matrice&);
    friend istream& operator>> (istream&,Matrice&);
    friend ostream& operator<< (ostream&, Matrice&);
};

class Matrice_oarecare: public Matrice
{
    int lin, col;
public:
    Matrice_oarecare();
    Matrice_oarecare(const Matrice_oarecare&);
    Matrice_oarecare(int l,int c);
    ~Matrice_oarecare();
    Matrice_oarecare operator+(Matrice_oarecare&);
    Matrice_oarecare& operator=(const Matrice_oarecare&);
        ///FRIEND
    friend ifstream& operator>> (ifstream&,Matrice_oarecare&);
    friend istream& operator>> (istream&,Matrice_oarecare&);
    friend ostream& operator<< (ostream&, Matrice_oarecare&);
        ///CITIRI
    void in_stream (istream& in);
    void f_stream (ifstream& fin);
    void out_stream (ostream& out);
};

class Matrice_patratica: public Matrice
{
    int dim;
public:
    Matrice_patratica();
    Matrice_patratica(int x);
    Matrice_patratica(const Matrice_patratica& m);
    ~Matrice_patratica();
    Matrice_patratica operator+(Matrice_patratica&);
    Matrice_patratica operator*(int);
    operator*=(int);
    Matrice_patratica& operator=(const Matrice_patratica&);
    Complex* operator[] (int i);
    ///FRIEND
    friend ifstream& operator>> (ifstream&,Matrice_patratica&);
    friend istream& operator>> (istream&,Matrice_patratica&);
    friend ostream& operator<< (ostream&, Matrice_patratica&);
    ///ALTELE
    Complex DETERMINANT ();
    void in_stream (istream& in);
    void f_stream (ifstream& fin);
    void out_stream (ostream& out);
};

ifstream& operator>> (ifstream& fin,Matrice& m)
{
    m.f_stream(fin);
    return fin;
}

istream& operator>> (istream& in, Matrice& m)
{
    m.in_stream(in);
    return in;
}

ostream& operator<< (ostream& out, Matrice& m)
{
    m.out_stream(out);
    return out;
}

void Matrice_oarecare::in_stream (istream& in)
{
    in>>lin>>col;
    v=new Complex*[lin];
    for(int i=0;i<lin;i++)
    {
        v[i]=new Complex[col];
        for(int j=0;j<col;j++) in>>v[i][j];
    }
}

void Matrice_oarecare::f_stream (ifstream& fin)
{
    fin>>lin>>col;
    v=new Complex*[lin];
    for(int i=0;i<lin;i++)
    {
        v[i]=new Complex[col];
        for(int j=0;j<col;j++) fin>>v[i][j];
    }
}

void Matrice_oarecare::out_stream (ostream& out)
{
    for(int i=0;i<lin;i++)
    {
        for(int j=0;j<col;j++) out<<v[i][j];
        out<<"\n";
    }
out<<"\n";
}

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


Matrice::Matrice(){v=NULL;}

Matrice::Matrice(int l,int c)
{
    v=new Complex*[l];
    for(int i=0;i<l;i++)
    {
        v[i]=new Complex[c];
        for(int j=0;j<c;j++) v[i][j](0,0);
    }
}

Matrice::~Matrice()
{
    if(v!=NULL) delete[] v;
    v=NULL;
}

ifstream& operator>> (ifstream& fin,Matrice_oarecare& mat)
{
    fin>>mat.lin>>mat.col;
    mat.v=new Complex*[mat.lin];
    for(int i=0;i<mat.lin;i++) mat.v[i]=new Complex[mat.col];
    for(int i=0;i<mat.lin;i++)
        for(int j=0;j<mat.col;j++) fin>>mat.v[i][j];
    return fin;
}

istream& operator>> (istream& in,Matrice_oarecare& mat)
{
    cout<<"Introduceti numarul de LINII si COLOANE: ";
    in>>mat.lin>>mat.col;
    mat.v=new Complex*[mat.lin];
    cout<<"Introduceti cate "<<mat.col<<" ELEMENTE pentru fiecare dintre cele "<<mat.lin<<" LINII:\n";
    for(int i=0;i<mat.lin;i++) mat.v[i]=new Complex[mat.col];
    for(int i=0;i<mat.lin;i++)
        for(int j=0;j<mat.col;j++) in>>mat.v[i][j];
    return in;
}

ostream& operator<< (ostream& out, Matrice_oarecare& mat)
{

    for(int i=0;i<mat.lin;i++)
    {
        for(int j=0;j<mat.col;j++) out<<mat.v[i][j];
        out<<"\n";
    }
cout<<"\n";
return out;
}

Matrice_oarecare::Matrice_oarecare()
{
lin=col=0;
}

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare& m)
{
lin=m.lin;
col=m.col;
v=new Complex*[lin];
for(int i=0;i<lin;i++) v[i]=new Complex[col];

for(int i=0;i<lin;i++)
    for(int j=0;j<col;j++) v[i][j]=m.v[i][j];
}

Matrice_oarecare::Matrice_oarecare(int l,int c):Matrice(l,c)
{
    lin=l; col=c;
}

Matrice_oarecare::~Matrice_oarecare()
{
for(int i=0;i<lin;i++) delete[] v[i];
delete[] v;
lin=col=0;
v=NULL;
}

Matrice_oarecare Matrice_oarecare::operator+(Matrice_oarecare& z)
{
    Matrice_oarecare sum(max(lin,z.lin),max(col,z.col));
    int lc=min(lin,z.lin), cc=min(col,z.col);   ///LINIE / COLOANA COMUNE

    for(int i=0;i<lc;i++)
    {
        for(int j=0;j<cc;j++)
            sum.v[i][j]=v[i][j]+z.v[i][j];

        for(int j=cc;j<sum.col;j++)
        {
            if(col>z.col) sum.v[i][j]=v[i][j];
            if(col<z.col) sum.v[i][j]=z.v[i][j];
        }
    }
    for(int i=lc;i<sum.lin;i++)
    {
            if(lin>z.lin) for(int j=0;j<col;j++) sum.v[i][j]=v[i][j];
            if(lin<z.lin) for(int j=0;j<z.col;j++) sum.v[i][j]=z.v[i][j];
    }
cout<<sum;
return sum;
}

Matrice_oarecare& Matrice_oarecare::operator=(const Matrice_oarecare& m)
{
lin=m.lin;
col=m.col;
v=new Complex*[lin];
for(int i=0;i<lin;i++)
{
    v[i]=new Complex[col];
    for(int j=0;j<col;j++) v[i][j]=m.v[i][j];
}
}


Matrice_patratica Matrice_patratica::operator*(int x)
{
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++) v[i][j]*=x;
}

Matrice_patratica::operator*=(int x)
{
    *this = *this * x;
}

Complex* Matrice_patratica::operator[](int i)
{
    return v[i];
}

Matrice_patratica::Matrice_patratica()
{
dim=0;
}

Matrice_patratica::Matrice_patratica(const Matrice_patratica& m)
{
dim=m.dim;
v=new Complex*[dim];
for(int i=0;i<dim;i++) v[i]=new Complex[dim];

for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++) v[i][j]=m.v[i][j];
}

Matrice_patratica::Matrice_patratica(int x)
{
    dim=x;
    v=new Complex*[dim];
    for(int i=0;i<dim;i++)
        {
        v[i]=new Complex[dim];
        for(int j=0;j<dim;j++) v[i][j](0,0);
        }

}

Matrice_patratica::~Matrice_patratica()
{
for(int i=0;i<dim;i++) delete[] v[i];
delete[] v;
dim=0;
v=NULL;
}


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

void afis(Vect* Vt)
{
    for(int i=1;i<=Vt->n;i++)
        cout<<Vt->sol[i]<<" ";
    cout<<" -> "<<sign(Vt)<<"\n";
}

void adun (Vect* Vt, Matr* Mt)
{
Complex x(Mt->M[0][Vt->sol[1]-1]);
int si=sign(Vt);
x*=si;

    for(int i=2;i<=Vt->n;i++) x*=Mt->M[i-1][Vt->sol[i]-1];


Mt->det+=x;
}

int ok(int* sol,int k)
{
    for(int i=1;i<k;i++)
        if(sol[i]==sol[k]) return 0;
    return 1;
}

void back (Vect* Vt, Matr* Mt, int k=1)
{
if(k==Vt->n+1) adun(Vt,Mt);
else
    for(int i=1;i<=Vt->n;i++)
    {
        Vt->sol[k]=i;
        if(ok(Vt->sol,k)) back(Vt,Mt,k+1);
    }
}

Complex Matrice_patratica::DETERMINANT()
{
Vect Vt; Matr Mt;
Vt.n=dim;
Vt.sol=new int[Vt.n+1];
Mt.M=*this;
Mt.det(0,0);

back(&Vt,&Mt);

return Mt.det;
}
