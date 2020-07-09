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

        if(!first && pfo[i]>0) cout<<"+";
        first=0;

        if(i==0 || pfo[i]!=1)cout<<pfo[i]; 

        if(i!=0)cout<<"x";
        if(i>1)cout<<"^"<<i;

    }
    return os;
}
polyFormatOutputer format(const poly &A)
{
    return polyFormatOutputer(A);
}