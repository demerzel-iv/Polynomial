#pragma once
#include "temps.h"
#include<cmath>

using std::acos;
using std::sin;
using std::cos;
const double pi=acos(-1.0);
class Image:public temps{
public:
	double r,i;
	Image(double R,double I):temps(),r(R),i(I){}
	virtual temps* inv()const{
		double len=r*r+i*i;
		temps *ret=new Image(r/len,-i/len);
		return ret;
	}
	virtual temps* add(const temps *A,const temps *B)const{
		double r1=dynamic_cast<const Image*>(A)->r,r2=dynamic_cast<const Image*>(B)->r;
		double i1=dynamic_cast<const Image*>(A)->i,i2=dynamic_cast<const Image*>(B)->i;
		temps *ret=new Image(r1+r2,i1+i2);
		return ret;
	}
	virtual temps* substract(const temps *A,const temps *B)const{
		double r1=dynamic_cast<const Image*>(A)->r,r2=dynamic_cast<const Image*>(B)->r;
		double i1=dynamic_cast<const Image*>(A)->i,i2=dynamic_cast<const Image*>(B)->i;
		temps *ret=new Image(r1-r2,i1-i2);
		return ret;
	}
	virtual temps* multiply(const temps *A,const temps *B)const{
		double r1=dynamic_cast<const Image*>(A)->r,r2=dynamic_cast<const Image*>(B)->r;
		double i1=dynamic_cast<const Image*>(A)->i,i2=dynamic_cast<const Image*>(B)->i;
		temps *ret=new Image(r1*r2-i1*i2,r1*i2+r2*i1);
		return ret;
	}
	virtual temps* divide(const temps *A,const temps *B)const{
		double r1=dynamic_cast<const Image*>(A)->r,r2=dynamic_cast<const Image*>(B)->r;
		double i1=dynamic_cast<const Image*>(A)->i,i2=dynamic_cast<const Image*>(B)->i;
		double len=r2*r2+i2*i2;
		r2=r2/len,i2=-i2/len;
		temps *ret=new Image(r1*r2-i1*i2,r1*i2+r2*i1);
		return ret;
	}
	virtual temps* origin(int times)const{
		temps *ret=new Image(cos(pi/times),sin(pi/times));
		return ret;
	}
	virtual temps* v()const{
		return new Image(r,i);
	}
	virtual void set(double v){
		r=v,i=0;
	}
	virtual void set(int v){
		r=v,i=0;
	}
	virtual int type()const{
		return type_image;
	}
	virtual void output(ostream &os)const{
		os<<"("<<r<<","<<i<<")";
	}
};
