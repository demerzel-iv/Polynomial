#include "Int.h"
#include<bits/stdc++.h>

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

temps* Int::add(const temps *A)const
{
	if(A->type() == typed) return Double(*this).add(A);

	temps *ret=new Int(
		(this->getValueInt() + A->getValueInt())%MOD
	);
	return ret;
}
temps* Int::substract(const temps *A)const
{
	if(A->type() == typed) return Double(*this).substract(A);

	temps *ret=new Int(
		(this->getValueInt() - A->getValueInt() + MOD)%MOD
	);
	return ret;
}
temps* Int::multiply(const temps *A)const
{
	if(A->type() == typed) return Double(*this).multiply(A);

	temps *ret=new Int(
		(this->getValueInt() * (long long)A->getValueInt())%MOD
	);
	return ret;
}
temps* Int::divide(const temps *A)const
{
	if(A->type() == typed) return Double(*this).divide(A);

	temps *ret=new Int(
		(this->getValueInt() * (long long)qpow(A->getValueInt(),MOD-2))%MOD
	);
	return ret;
}

temps* Int::origin(int times)const
{
	temps *ret=new Int(qpow(g,(MOD-1)/times));
	return ret;
}

temps* Int::v()const{return static_cast<temps*>(new Int(x));}
int Int::type()const{return typei;}
int Int::value()const{return x;}

void Int::set(double v){x=v;}
void Int::set(int v){x=v;}

bool Int::greater(const temps* A)const
{
	return this->getValueInt() > A->getValueInt();
}

void Int::output(ostream &os)const{os<<x;}

int Int::getValueInt() const {return x;}
double Int::getValueDouble() const {return x;}

Int::operator Double() const {return Double(x);}
