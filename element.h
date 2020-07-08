#pragma once
#include "Int.h"
#include "Double.h"
#include "Image.h"
#include <iostream>
using std::ostream;
class element{
private:
	temps* value;
public:
	element(){value=nullptr;}
	element(int x):value(static_cast<temps*>(new Int(x))){}
	element(double x):value(static_cast<temps*>(new Double(x))){};

	element(double r,double i):value(static_cast<temps*>(new Image(r,i))){};

	element(temps* v)
	{
		value=v;
	}
	element(const element &A)
	{
		value=A.value->v();
	}
	element(element &&A)
	{
		delete value;
		value=A.value;
	}
	friend element operator + (const element &A,const element &B);
	friend element operator - (const element &A,const element &B);
	friend element operator * (const element &A,const element &B);
	friend element operator / (const element &A,const element &B);
	friend bool operator < (const element &A,const element &B);
	friend bool operator <= (const element &A,const element &B);
	friend bool operator > (const element &A,const element &B);
	friend bool operator >= (const element &A,const element &B);
	friend bool operator == (const element &A,const element &B);
	friend bool operator != (const element &A,const element &B);
	

	friend element inv(const element &A);


	element& operator = (const element &A)
	{
		value=A.value->v();
		return *this;
	}
	element& operator = (element &&A)
	{
		delete value;
		value=A.value;
		return *this;
	}
	element& operator = (const int &A)
	{
		value->set(A);
		return *this;
	}
	element& operator = (const double &A)
	{
		value->set(A);
		return *this;
	}

	element origin(int times)
	{
		return element(value->origin(times));
	}
	friend ostream& operator << (ostream& os, const element &A);
	void setint(int x=0)
	{
		value=static_cast<temps*>(new Int(x));
	}
	void setdouble(double x=0.0)
	{
		value=static_cast<temps*>(new Double(x));
	}
	void setimage(double r,double i)
	{
		value=static_cast<temps*>(new Image(r,i));
	}
	~element(){
		delete value;
	}
	temps* getvalue(){return value;}
};
