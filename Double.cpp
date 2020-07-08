#include "Double.h"
temps* Double::add(const temps *A,const temps *B)const
{
	temps* ret=new Double(((dynamic_cast<const Double*>(A))->x)+((dynamic_cast<const Double*>(B))->x));
	return ret;
}
temps* Double::substract(const temps *A,const temps *B)const
{
	temps* ret=new Double(((dynamic_cast<const Double*>(A))->x)-((dynamic_cast<const Double*>(B))->x));
	return ret;
}
temps* Double::multiply(const temps *A,const temps *B)const
{
	temps* ret=new Double(((dynamic_cast<const Double*>(A))->x)*((dynamic_cast<const Double*>(B))->x));
	return ret;
}
temps* Double::divide(const temps *A,const temps *B)const
{
	temps* ret=new Double(((dynamic_cast<const Double*>(A))->x)/((dynamic_cast<const Double*>(B))->x));
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

bool Double::greater(const temps* A,const temps* B)const
{
	return ((dynamic_cast<const Double*>(A))->x)>((dynamic_cast<const Double*>(B))->x);
}

void Double::output(ostream &os)const{os<<x;}

