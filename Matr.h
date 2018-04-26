#include "COMPLEX.h"


class Matrice
{
protected:
    Complex **v;
public:
    Matrice(int l,int c);
    ~Matrice();
    ///STREAM
    virtual void in_stream (istream& in) {}
    virtual void f_stream (ifstream& fin) {}
    virtual void out_stream (ostream& out) {}
    ///FRIEND
    friend ifstream& operator>> (ifstream&,Matrice&);
    friend istream& operator>> (istream&,Matrice&);
    friend ostream& operator<< (ostream&, Matrice&);
    ///ALTELE
    virtual Complex DETERMINANT () {Complex mi(-1,0); return mi;}
    virtual int trio_sup() {return -1;}
    virtual int trio_inf() {return -1;}
    virtual int triunghiulara() {return -1;}
    virtual int diagonala() {return -1;}
};


Matrice::Matrice(int l=0,int c=0)
{
    if(l==0 && c==0) v=NULL;
    else
{
    v=new Complex*[l];
    for(int i=0;i<l;i++)
    {
        v[i]=new Complex[c];
        for(int j=0;j<c;j++) v[i][j](0,0);
    }
}
}

Matrice::~Matrice()
{
    if(v!=NULL) delete[] v;
    v=NULL;
}

///FRIEND

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
