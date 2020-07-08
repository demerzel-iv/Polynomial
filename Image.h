#pragma once
#include "temps.h"
#include<cmath>

using std::acos;
using std::sin;
using std::cos;
const double pi=acos(-1.0);
class Image:public temps{
	double r,i;
public:
	Image(double R,double I):temps(),r(R),i(I){}

	virtual temps* inv()const;

	virtual temps* add(const temps *A,const temps *B)const;
	virtual temps* substract(const temps *A,const temps *B)const;
	virtual temps* multiply(const temps *A,const temps *B)const;
	virtual temps* divide(const temps *A,const temps *B)const;

	virtual temps* origin(int times)const;

	virtual temps* v()const;
	virtual int type()const;

	virtual void set(double v);
	virtual void set(int v);

	virtual void output(ostream &os)const;
};
