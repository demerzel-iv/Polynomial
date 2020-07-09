#include "polymath.h"
#include "polynomial.h"
#include "element.h"

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
    return ret;
}
poly polycalc::inverse(const poly &A) //calc inverse mod x^n
{
    poly X0(1),X(0),a(0);

    X0[0]=inv(A[0]);

    for(int k=1;k<n;k<<=1)
    {
        a=poly(k*2);
        for(int i=0;i<k*2;i++)
            a[i]=A[i];

        X=2*X0-a*X0*X0;

        X0=poly(k*2);
        for(int i=0;i<k*2;i++)
            X0[i]=X[i];
    }

    poly ret(n);
    for(int i=0;i<n;i++)
        ret[i]=X0[i];
    return ret;
}
poly polycalc::ln(const poly &A) //calc ln mod x^n
{
}
poly polycalc::exp(const poly &A) // calc exp mod x^n
{
}