#include "Image.h"
temps* Image::inv()const{
	double len=r*r+i*i;
	temps *ret=new Image(r/len,-i/len);
	return ret;
}

temps* Image::add(const temps *A,const temps *B)const{
	double r1=dynamic_cast<const Image*>(A)->r,r2=dynamic_cast<const Image*>(B)->r;
	double i1=dynamic_cast<const Image*>(A)->i,i2=dynamic_cast<const Image*>(B)->i;
	temps *ret=new Image(r1+r2,i1+i2);
	return ret;
}
temps* Image::substract(const temps *A,const temps *B)const{
	double r1=dynamic_cast<const Image*>(A)->r,r2=dynamic_cast<const Image*>(B)->r;
	double i1=dynamic_cast<const Image*>(A)->i,i2=dynamic_cast<const Image*>(B)->i;
	temps *ret=new Image(r1-r2,i1-i2);
	return ret;
}
temps* Image::multiply(const temps *A,const temps *B)const{
	double r1=dynamic_cast<const Image*>(A)->r,r2=dynamic_cast<const Image*>(B)->r;
	double i1=dynamic_cast<const Image*>(A)->i,i2=dynamic_cast<const Image*>(B)->i;
	temps *ret=new Image(r1*r2-i1*i2,r1*i2+r2*i1);
	return ret;
}
temps* Image::divide(const temps *A,const temps *B)const{
	double r1=dynamic_cast<const Image*>(A)->r,r2=dynamic_cast<const Image*>(B)->r;
	double i1=dynamic_cast<const Image*>(A)->i,i2=dynamic_cast<const Image*>(B)->i;
	double len=r2*r2+i2*i2;
	r2=r2/len,i2=-i2/len;
	temps *ret=new Image(r1*r2-i1*i2,r1*i2+r2*i1);
	return ret;
}

temps* Image::origin(int times)const{
	temps *ret=new Image(cos(pi/times),sin(pi/times));
	return ret;
}

temps* Image::v()const{return new Image(r,i);}
int Image::type()const{return type_image;}

void Image::set(double v){r=v,i=0;}
void Image::set(int v){r=v,i=0;}

void Image::output(ostream &os)const{os<<"("<<r<<","<<i<<")";}
