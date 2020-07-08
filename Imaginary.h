#include<iostream>
using std::ostream;
class Imaginary{
	double r,i;
public:
	Imaginary():r(0),i(0){}
	Imaginary(double R,double I):r(R),i(I){}
	Imaginary inv()const;

	friend Imaginary operator + (const Imaginary &A,const Imaginary &B);
	friend Imaginary operator - (const Imaginary &A,const Imaginary &B);
	friend Imaginary operator * (const Imaginary &A,const Imaginary &B);
	friend Imaginary operator / (const Imaginary &A,const Imaginary &B);
	friend ostream& operator << (ostream &os, const Imaginary &A);

	Imaginary& operator = (const int &x){r=x,i=0; return *this;}
	Imaginary& operator = (const double &x){r=x,i=0;return *this;}

	double rpart()const{return r;}
	double ipart()const{return i;}
};
