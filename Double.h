#pragma once
#include "temps.h"
class Double:public temps{
	double x;
public:
	Double(double X=0.0):temps(),x(X){}

	virtual temps* inv()const;

	virtual temps* add(const temps *A,const temps *B)const;
	virtual temps* substract(const temps *A,const temps *B)const;
	virtual temps* multiply(const temps *A,const temps *B)const;
	virtual temps* divide(const temps *A,const temps *B)const;

	virtual temps* origin(int times)=delete;

	virtual temps* v()const;
	virtual int type()const;
	double value()const;

	virtual void set(double v);
	virtual void set(int v);

	virtual bool greater(const temps* A,const temps* B)const;

	virtual void output(ostream &os)const;
};
