#pragma once
#include "temps.h"

class Image:public temps{
	Imaginary x;
public:
	Image(double R,double I):temps(),x(R,I){}
	Image(const Imaginary &X):temps(),x(X){}
	Imaginary qpow(Imaginary v,int y)const;

	virtual temps* inv()const;

	virtual temps* add(const temps *A)const;
	virtual temps* substract(const temps *A)const;
	virtual temps* multiply(const temps *A)const;
	virtual temps* divide(const temps *A)const;
	virtual temps* qpow(const temps *A,const int &B)const;

	virtual temps* origin(int times)const;

	virtual temps* v()const;
	virtual int type()const;
	double valuer()const;
	double valuei()const;
	Imaginary valuex()const;

	virtual void set(double vr,double vi);
	virtual void set(double v);
	virtual void set(int v);

	virtual void output(ostream &os)const;

	virtual double getValueReal() const override;
	virtual double getValueImage() const override;
	virtual Imaginary getValueImaginary() const override;
};
