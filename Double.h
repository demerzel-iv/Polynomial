#pragma once
#include "temps.h"
class Double:public temps{
	double x;
public:
	Double(double X=0.0):temps(),x(X){}
	double qpow(double v,int y)const;

	virtual temps* inv()const;

	virtual temps* add(const temps *A)const;
	virtual temps* substract(const temps *A)const;
	virtual temps* multiply(const temps *A)const;
	virtual temps* divide(const temps *A)const;
	virtual temps* qpow(const temps *A,const int &B)const;

	virtual temps* origin(int times)=delete;
	virtual temps* exp()const;

	virtual temps* v()const;
	virtual int type()const;
	double value()const;

	virtual void set(double v);
	virtual void set(int v);

	virtual bool greater(const temps* A)const;

	virtual void output(ostream &os)const;

	virtual int getValueInt() const override ;
	virtual double getValueDouble() const override;
};
