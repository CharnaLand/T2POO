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
        ///FRIEND
    friend ifstream& operator>> (ifstream&,Matrice_oarecare&);
    friend istream& operator>> (istream&,Matrice_oarecare&);
    friend ostream& operator<< (ostream&, Matrice_oarecare&);
        ///CITIRI
    void in_stream (istream& in);
    void f_stream (ifstream& fin);
    void out_stream (ostream& out);
};


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

