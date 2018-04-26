#include "Matr.h"

class Matrice_oarecare: public Matrice
{
    int lin, col;
public:
    Matrice_oarecare(int l=0,int c=0);
    Matrice_oarecare(const Matrice_oarecare&);
    ~Matrice_oarecare();
    Matrice_oarecare operator+(Matrice_oarecare&);
    Matrice_oarecare& operator=(const Matrice_oarecare&);
    Complex* operator[] (int i);
        ///FRIEND
    friend ifstream& operator>> (ifstream&,Matrice_oarecare&);
    friend istream& operator>> (istream&,Matrice_oarecare&);
    friend ostream& operator<< (ostream&, Matrice_oarecare&);
        ///CITIRI
    void in_stream (istream& in);
    void f_stream (ifstream& fin);
    void out_stream (ostream& out);
        ///DIAGONALA SI TRIUNGHIULARA
    int trio_sup();
    int trio_inf();
    int triunghiulara();
    int diagonala();
    ///DETERMINANT
    Complex DETERMINANT();
};

int Matrice_oarecare::trio_sup()
{
Complex ZERO(0,0);
    if(lin!=col) return -1;
    for(int i=1;i<lin;i++)
        for(int j=0;j<i-1;j++)
            if(v[i][j]!=ZERO) return 0;
    return 1;
}

int Matrice_oarecare::trio_inf()
{
Complex ZERO(0,0);
    if(lin!=col) return -1;
    for(int i=0;i<lin-1;i++)
        for(int j=i+1;j<col;j++)
            if(v[i][j]!=ZERO) return 0;
    return 1;
}

int Matrice_oarecare::triunghiulara()
{
    if(lin!=col) return -1;
    int s=trio_sup(), i=trio_inf();
    if(s+i==1) return 1;
    return 0;
}

int Matrice_oarecare::diagonala()
{
    if(lin!=col) return -1;
    if(trio_inf() && trio_sup()) return 1;
    return 0;
}
///2 1 2 3 1 0 -2 1 1 -2


Matrice_oarecare::Matrice_oarecare(int l,int c):Matrice(l,c), lin(l), col(c)
{
}

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare& m):Matrice(m.lin,m.col),lin(m.lin),col(m.col)
{
for(int i=0;i<lin;i++)
    for(int j=0;j<col;j++) v[i][j]=m.v[i][j];
}

Matrice_oarecare::~Matrice_oarecare()
{
for(int i=0;i<lin;i++) delete[] v[i];
delete[] v;
lin=col=0;
v=NULL;
}

///FRIEND
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


///OPERATORI

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

Complex* Matrice_oarecare::operator[](int i)
{
    return v[i];
}


///STREAM


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

///DETERMINANT - DE MODIFICAT
struct Vect_O
{
    int* sol;
    int n;
};
struct Matr_O
{
    Matrice_oarecare M;
    Complex det;
};

int sign (Vect_O* Vt)
{
int ala=1;
    for(int  i=1;i<Vt->n;i++)
        for(int j=i+1;j<=Vt->n;j++)
        if(i!=j) ala*=(Vt->sol[j]-Vt->sol[i]);
if(ala>0) return 1;
else return -1;
}

void afis(Vect_O* Vt)
{
    for(int i=1;i<=Vt->n;i++)
        cout<<Vt->sol[i]<<" ";
    cout<<" -> "<<sign(Vt)<<"\n";
}

void adun (Vect_O* Vt, Matr_O* Mt)
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

void back (Vect_O* Vt, Matr_O* Mt, int k=1)
{
if(k==Vt->n+1) adun(Vt,Mt);
else
    for(int i=1;i<=Vt->n;i++)
    {
        Vt->sol[k]=i;
        if(ok(Vt->sol,k)) back(Vt,Mt,k+1);
    }
}

Complex Matrice_oarecare::DETERMINANT()
{
if(lin!=col)
{
    Complex NOPE(-1,0);
    return NOPE;
}
Vect_O Vt; Matr_O Mt;
Vt.n=lin;
Vt.sol=new int[Vt.n+1];
Mt.M=*this;
Mt.det(0,0);

back(&Vt,&Mt);

return Mt.det;
}
