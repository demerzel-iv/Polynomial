#pragma once
#include "temps.h"
#include "Double.h"
class Int:public temps{
	static const int MOD=998244353;
	static const int g=3;
	int x;
public:
	Int(int X=0):temps(),x(X){}

	int qpow(int v,int y)const;
	virtual temps* inv()const;

	virtual temps* add(const temps *A)const;
	virtual temps* substract(const temps *A)const;
	virtual temps* multiply(const temps *A)const;
	virtual temps* divide(const temps *A)const;
	virtual temps* qpow(const temps *A,const int &B)const;

	virtual temps* origin(int times)const;
	virtual temps* exp()const;

	virtual temps* v()const;
	virtual int type()const;
	int value()const;

	virtual void set(double v);
	virtual void set(int v);

	virtual bool greater(const temps* A)const;

	virtual void output(ostream &os)const;

	virtual int getValueInt() const override ;
	virtual double getValueDouble() const override;

	operator Double() const;
};
