#pragma once
#include "temps.h"
class Double:public temps{
public:
	double x;
	Double(double X=0.0):temps(),x(X){}
	virtual temps* inv()const{
		temps* ret=static_cast<temps*>(new Double(1.0/x));
		return ret;
	}
	virtual temps* add(const temps *A,const temps *B)const{
		temps* ret=new Double(((dynamic_cast<const Double*>(A))->x)+((dynamic_cast<const Double*>(B))->x));
		return ret;
	}
	virtual temps* substract(const temps *A,const temps *B)const{
		temps* ret=new Double(((dynamic_cast<const Double*>(A))->x)-((dynamic_cast<const Double*>(B))->x));
		return ret;
	}
	virtual temps* multiply(const temps *A,const temps *B)const{
		temps* ret=new Double(((dynamic_cast<const Double*>(A))->x)*((dynamic_cast<const Double*>(B))->x));
		return ret;
	}
	virtual temps* divide(const temps *A,const temps *B)const{
		temps* ret=new Double(((dynamic_cast<const Double*>(A))->x)/((dynamic_cast<const Double*>(B))->x));
		return ret;
	}
	virtual temps* origin(int times)=delete;
	virtual temps* v()const{
		return new Double(x);
	}
	virtual void set(double v){
		x=v;
	}
	virtual void set(int v){
		x=v;
	}
	virtual int type()const{
		return typed;
	}
	virtual bool greater(const temps* A,const temps* B)const{
		return ((dynamic_cast<const Double*>(A))->x)>((dynamic_cast<const Double*>(B))->x);
	}
	double value()const{return x;}
	virtual void output(ostream &os)const{
		os<<x;
	}
};
