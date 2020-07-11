#include "polymath.h"
#include "poly.h"
#include "element.h"
#include "polyvar.h"
#include <bits/stdc++.h>

element getinv(const element &A) { return inv(A); }
element getexp(const element &A) { return exp(A); }

const polyvar &x = polyvar::x;

poly polycalc::derivative(const poly &A)
{
    poly ret(A.size()-1);
    for(int i=0;i<A.size()-1;i++)
        ret[i]=A[i+1]*(i+1);
    return ret;
}
poly polycalc::intgration(const poly &A)  //with C=0
{
    poly ret(A.size()+1);
    for(int i=1;i<A.size()+1;i++)
        ret[i]=A[i-1]/i;
    if(A.type()==typed)
        ret[0]=ret[0]*1.0;
    return ret;
}
poly polycalc::inv(const poly &A) //calc inverse mod x^n
{
    //cout<<"calc inverse of : "<<A<<endl;

    poly X0(1),X;
    X0[0]=getinv(A[0]);
    for(int k=1;k<n;k<<=1)
    {
        poly a=A%(x^(k*2));
        X=2*X0-a*X0*X0;
        X0=X%(x^(k*2));
    }
    return X0%(x^n);
}
poly polycalc::ln(const poly &A) //calc ln mod x^n
{
    if(A.type()==typei)
    {
        if(A[0]!=1) return ln(A*1.0);
        else return intgration(
            derivative(A) * inv(A)
        ) % (x^n);
    }
    else
    {
        double Const=std::log(A[0].getvalue()->getValueDouble());
        if(A.type()==typed && A.size()==1)
            return {Const} ;
        else
            return intgration(
                derivative(A) * inv(A)
            ) % (x^n) + Const;
    }
}
poly polycalc::exp(const poly &A) // calc exp mod x^n
{
    poly X0(1),X;
    X0[0]=getexp(A[0]);
    for(int k=1;k<n;k<<=1)
    {
        poly a=A%(x^(k*2));
        polycalc tmp(k*2);
        X=X0*(a-tmp.ln(X0)+1);
        X0=X%(x^(k*2));
    }
    return X0%(x^n);
}