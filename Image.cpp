#include "Image.h"
#include<cmath>

using std::acos;
using std::sin;
using std::cos;
const double pi=acos(-1.0);

temps* Image::inv()const{
	temps *ret=new Image(x.inv());
	return ret;
}

temps* Image::add(const temps *A)const{
	temps *ret=new Image((this->getValueImaginary())+(A->getValueImaginary()));
	return ret;
}
temps* Image::substract(const temps *A)const{
	temps *ret=new Image((this->getValueImaginary())-(A->getValueImaginary()));
	return ret;
}
temps* Image::multiply(const temps *A)const{
	temps *ret=new Image((this->getValueImaginary())*(A->getValueImaginary()));
	return ret;
}
temps* Image::divide(const temps *A)const{
	temps *ret=new Image((this->getValueImaginary())/(A->getValueImaginary()));
	return ret;
}

temps* Image::origin(int times)const{
	temps *ret=new Image(cos(2*pi/times),sin(2*pi/times));
	return ret;
}

temps* Image::v()const{return new Image(x.rpart(),x.ipart());}
int Image::type()const{return type_image;}
double Image::valuer()const{return x.rpart();}
double Image::valuei()const{return x.ipart();}

void Image::set(double vr,double vi){x=Imaginary(vr,vi);}
void Image::set(double v){x=v;}
void Image::set(int v){x=v;}

void Image::output(ostream &os)const{os<<x;}

double Image::getValueReal() const {return x.rpart();}
double Image::getValueImage() const {return x.ipart();}
Imaginary Image::getValueImaginary() const {return x;};
