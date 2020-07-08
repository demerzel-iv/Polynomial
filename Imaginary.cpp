#include"Imaginary.h"

Imaginary Imaginary::inv()const
{
	double L=r*r+i*i;
	return Imaginary(r/L,-i/L);
}

Imaginary operator + (const Imaginary &A,const Imaginary &B)
{
	return Imaginary(A.r+B.r,A.i+B.i);
}
Imaginary operator - (const Imaginary &A,const Imaginary &B)
{
	return Imaginary(A.r-B.r,A.i-B.i);
}
Imaginary operator * (const Imaginary &A,const Imaginary &B)
{
	return Imaginary{A.r*B.r-A.i*B.i,A.r*B.i+A.i*B.r};
}
Imaginary operator / (const Imaginary &A,const Imaginary &B)
{
	return A*B.inv();
}

ostream& operator << (ostream &os, const Imaginary &A)
{
	os<<"("<<A.r<<","<<A.i<<")";
	return os;
}
