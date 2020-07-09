#include <bits/stdc++.h>
#include "Double.h"
const double eps=1e-9;
double Double::qpow(double v,int y)const
{
	double z=1;
	for(;y;y>>=1,v=v*v)
		if(y&1)z=z*v;
	return z;
}
temps* Double::add(const temps *A)const
{
	temps* ret = new Double (
		this->getValueDouble() + A->getValueDouble()
	);
	return ret;
}
temps* Double::substract(const temps *A)const
{
	temps* ret = new Double (
		this->getValueDouble() - A->getValueDouble()
	);
	return ret;
}
temps* Double::multiply(const temps *A)const
{
	temps* ret = new Double (
		this->getValueDouble() * A->getValueDouble()
	);
	return ret;
}
temps* Double::divide(const temps *A)const
{
	temps* ret = new Double (
		this->getValueDouble() / A->getValueDouble()
	);
	return ret;
}
temps* Double::qpow(const temps *A,const int &B)const
{
	temps *ret=new Double(
		qpow(this->getValueDouble(),B)
	);
	return ret;
}
temps* Double::inv()const
{
	temps* ret=static_cast<temps*>(new Double(1.0/x));
	return ret;
}

temps* Double::v()const{return new Double(x);}
int Double::type()const{return typed;}

void Double::set(double v){x=v;}
void Double::set(int v){x=v;}
double Double::value()const{return x;}

bool Double::greater(const temps* A)const
{
	return this->getValueDouble() > A->getValueDouble() + eps;
}

void Double::output(ostream &os)const{os<<x;}

int Double::getValueInt() const {return x;}
double Double::getValueDouble() const {return x;}

temps* Double::exp() const
{
	return new Double(std::exp(x));
}