#include "Int.h"

int Int::qpow(int v,int y)const
{
	int z=1;
	for(;y;y>>=1,v=(long long)v*v%MOD)
		if(y&1)z=(long long)z*v%MOD;
	return z;
}
temps* Int::inv()const
{
	temps *ret=new Int(qpow(x,MOD-2));
	return ret;
}

temps* Int::add(const temps *A,const temps *B)const
{
	temps *ret=new Int((((dynamic_cast<const Int*>(A))->x)+((dynamic_cast<const Int*>(B))->x))%MOD);
	return ret;
}
temps* Int::substract(const temps *A,const temps *B)const
{
	temps *ret=new Int((((dynamic_cast<const Int*>(A))->x)-((dynamic_cast<const Int*>(B))->x)+MOD)%MOD);
	return ret;
}
temps* Int::multiply(const temps *A,const temps *B)const
{
	temps *ret=new Int((((dynamic_cast<const Int*>(A))->x)*(long long)((dynamic_cast<const Int*>(B))->x))%MOD);
	return ret;
}
temps* Int::divide(const temps *A,const temps *B)const
{
	temps *ret=new Int((((dynamic_cast<const Int*>(A))->x)*(long long)qpow((dynamic_cast<const Int*>(B))->x,MOD-2))%MOD);
	return ret;
}

temps* Int::origin(int times)const
{
	temps *ret=new Int(qpow(g,MOD-2));
	return ret;
}

temps* Int::v()const{return new Int(x);}
int Int::type()const{return typei;}

void Int::set(double v){x=v;}
void Int::set(int v){x=v;}

bool Int::greater(const temps* A,const temps* B)const
{
	return ((dynamic_cast<const Int*>(A))->x)>((dynamic_cast<const Int*>(B))->x);
}

void Int::output(ostream &os)const{os<<x;}
