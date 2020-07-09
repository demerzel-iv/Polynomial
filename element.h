#pragma once
#include "Int.h"
#include "Double.h"
#include "Image.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
class element{
private:
	temps* value;
public:
	//element(){value=nullptr;}
	element(int x = 0):value(static_cast<temps*>(new Int(x))){}
	element(double x):value(static_cast<temps*>(new Double(x))){}
	element(double r,double i):value(static_cast<temps*>(new Image(r,i))){}

	element(temps* v):value(v){}
	element(const element &A){value=A.value->v();}
	element(element &&A)
	{
		value=A.value;
		A.value=nullptr;
	}

	friend element operator + (const element &A,const element &B);
	friend element operator - (const element &A,const element &B);
	friend element operator * (const element &A,const element &B);
	friend element operator / (const element &A,const element &B);
	friend element operator ^ (const element &A,const int &B);
	friend bool operator < (const element &A,const element &B);
	friend bool operator <= (const element &A,const element &B);
	friend bool operator > (const element &A,const element &B);
	friend bool operator >= (const element &A,const element &B);
	friend bool operator == (const element &A,const element &B);
	friend bool operator != (const element &A,const element &B);
	

	friend element inv(const element &A);


	element& operator = (const element &A)
	{
		if(value!=nullptr&&value!=A.value) delete value;
		value=A.value->v();
		return *this;
	}
	element& operator = (element &&A)
	{
		if(value!=nullptr&&value!=A.value) delete value;
		value=A.value;
		A.value=nullptr;
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

	element origin(int times);

	void setint(int x=0);
	void setdouble(double x=0.0);
	void setimage(double r=0,double i=0);

	temps* getvalue();
	int type()const;

	friend ostream& operator << (ostream& os, const element &A);

	~element(){if(value!=nullptr) delete value;}
};
