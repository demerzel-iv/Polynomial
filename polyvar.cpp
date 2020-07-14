#include "polyvar.h"

polyvar polyvar::x;

polyvar::operator poly() const
{
    return x^1;
}
poly operator ^ (const polyvar &x,int exp)
{
    poly ret (exp+1);
    ret[exp]=1;
    return ret;
}
poly operator + (const polyvar &x,const polyvar &y) {return {0,2};}
poly operator - (const polyvar &x,const polyvar &y) {return {0};}
poly operator * (const polyvar &x,const polyvar &y) {return {0,0,1};}
poly operator / (const polyvar &x,const polyvar &y) {return {1};}

unsigned int polyFormatOutputer::size() const
{
    return A.size();
}
element polyFormatOutputer::operator[](int i) const
{
    return A[i];
}
ostream& operator << (ostream &os, const polyFormatOutputer &pfo)
{
    bool first=1;

    for(int i=0;i<(int)pfo.size();i++)
    {
        if(pfo[i]==0) continue;

        if(!first && pfo[i]>0) os<<"+";
        first=0;

        if(i==0 || pfo[i]!=1)os<<pfo[i]; 

        if(i!=0)os<<"x";
        if(i>1)os<<"^"<<i;

    }
    if(first) os<<"0";
    return os;
}
polyFormatOutputer format(const poly &A)
{
    return polyFormatOutputer(A);
}
