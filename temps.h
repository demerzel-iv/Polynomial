#pragma once
#include<iostream>
using std::ostream;
const int typed=0;
const int typei=1;
const int type_image=2;
class temps{
public:
	virtual temps* add(const temps* A)const=0;
	virtual temps* substract(const temps *A)const=0;
	virtual temps* multiply(const temps *A)const=0;
	virtual temps* divide(const temps *A)const=0;
	virtual temps* v()const=0;
	virtual temps* inv()const=0;
	virtual temps* origin(int times)const{return nullptr;}
	virtual void set(double v)=0;
	virtual void set(int v)=0;
	virtual int type()const=0;
	virtual bool greater(const temps *A)const{return 0;}
	virtual void output(ostream &os)const=0;
	virtual int getValueInt()const{return 0;}
	virtual double getValueDouble()const{return 0;}
	virtual double getValueReal()const{return 0;}
	virtual double getValueImage()const{return 0;}
};
