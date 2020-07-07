#include "polymath.h"
#include "polynomial.h"

ipoly polycalc::inv(const ipoly &A) //calc inverse mod x^n
{
    ipoly X0(1),X,a;

    X0[0]=ipoly::inv(A[0]);

    for(int k=1;k<n;k<<=1)
    {
        printf("k = %d\n",k);
        a=ipoly(k*2);
        for(int i=0;i<k*2;i++)
            a[i]=A[i];

        X=2*X0-a*X0*X0;

        X0=ipoly(k*2);
        for(int i=0;i<k*2;i++)
            X0[i]=X[i];
    }

    printf("?\n");

    ipoly ret(n);
    for(int i=0;i<n;i++)
        ret[i]=X0[i];
    printf("???\n");
    return ret;
}
ipoly polycalc::ln(const ipoly &A) //calc ln mod x^n
{
}
ipoly polycalc::exp(const ipoly &A) // calc exp mod x^n
{
}
ipoly polycalc::pow(const ipoly &A,int k) //calc A^k mod x^n
{
}