#include "Image.h"
temps* Image::inv()const{
	double len=r*r+i*i;
	temps *ret=new Image(r/len,-i/len);
	return ret;
}

temps* Image::add(const temps *A)const{
	double r1=this->getValueReal(),r2=A->getValueReal();
	double i1=this->getValueImage(),i2=A->getValueImage();
	temps *ret=new Image(r1+r2,i1+i2);
	return ret;
}
temps* Image::substract(const temps *A)const{
	double r1=this->getValueReal(),r2=A->getValueReal();
	double i1=this->getValueImage(),i2=A->getValueImage();
	temps *ret=new Image(r1-r2,i1-i2);
	return ret;
}
temps* Image::multiply(const temps *A)const{
	double r1=this->getValueReal(),r2=A->getValueReal();
	double i1=this->getValueImage(),i2=A->getValueImage();
	temps *ret=new Image(r1*r2-i1*i2,r1*i2+r2*i1);
	return ret;
}
temps* Image::divide(const temps *A)const{
	double r1=this->getValueReal(),r2=A->getValueReal();
	double i1=this->getValueImage(),i2=A->getValueImage();
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
double Image::valuer()const{return r;}
double Image::valuei()const{return i;}

void Image::set(double vr,double vi){r=vr,i=vi;}
void Image::set(double v){r=v,i=0;}
void Image::set(int v){r=v,i=0;}

void Image::output(ostream &os)const{os<<"("<<r<<","<<i<<")";}

double Image::getValueReal() const {return r;}
double Image::getValueImage() const {return i;}