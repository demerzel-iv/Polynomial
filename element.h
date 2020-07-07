#include "Int.h"
#include "Double.h"
class element{
private:
	temps* value;
public:
	element(){value=nullptr;}
	element(int x)
	{
		value=static_cast<temps*>(new Int(x));
	}
	element(double x)
	{
		value=static_cast<temps*>(new Double(x));
	}
	element(temps* v)
	{
		value=v;
	}
	friend element operator + (const element &A,const element &B);
	friend element operator - (const element &A,const element &B);
	friend element operator * (const element &A,const element &B);
	friend element operator / (const element &A,const element &B);
	friend element inv(const element &A);
	element& operator = (const element &A)
	{
		value=A.value->v();
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
	element& operator = (ipoly &&A)
	{
		delete value;
		value=A.value;
		return *this;
	}
	ostream& operator << (ostream& os, const element &A);
	void setint(int x=0)
	{
		value=static_cast<temps*>(new Int(x));
	}
	void setdouble(double x=0.0)
	{
		value=static_cast<temps*>(new Double(x));
	}
	~element(){
		delete value;
	}
};
element operator + (const element &A,const element &B){
	return element(A.value->add(A.value,B.value));
}
element operator - (const element &A,const element &B){
	return element(A.value->substract(A.value,B.value));
}
element operator * (const element &A,const element &B){
	return element(A.value->multiply(A.value,B.value));
}
element operator / (const element &A,const element &B){
	return element(A.value->devide(A.value,B.value));
}
element inv(const element &A){
	return element(A.value->inv());
}
ostream& operator << (ostream& os, const element &A){
	if(A.value->type()==typei)
		os<<(dynamic_cast<Int*>(A->value))->x;
	else if(A.value->type()==typed)
		os<<(dynamic_cast<Double*>(A->value))->x;
	return os;
}
