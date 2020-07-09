#include "element.h"
#include<bits/stdc++.h>
using namespace std;
element operator + (const element &A,const element &B){
	return element(A.value->add(B.value));
}
element operator - (const element &A,const element &B){
	return element(A.value->substract(B.value));
}
element operator * (const element &A,const element &B){
	return element(A.value->multiply(B.value));
}
element operator / (const element &A,const element &B){
	return element(A.value->divide(B.value));
}
bool operator < (const element &A,const element &B){
	return B.value->greater(B.value);
}
bool operator > (const element &A,const element &B){
	return A.value->greater(B.value);
}
bool operator <= (const element &A,const element &B){
	return !(A>B);
}
bool operator >= (const element &A,const element &B){
	return !(B>A);
}
bool operator == (const element &A,const element &B){
	return !(A>B) && !(B>A);
}
bool operator != (const element &A,const element &B){
	return !(A==B);
}


element inv(const element &A){return element(A.value->inv());}

element element::origin(int times){return element(value->origin(times));}

void element::setint(int x){value=static_cast<temps*>(new Int(x));}
void element::setdouble(double x){value=static_cast<temps*>(new Double(x));}
void element::setimage(double r,double i){value=static_cast<temps*>(new Image(r,i));}

temps* element::getvalue(){return value;}
int element::type() const{return value->type();}

ostream& operator << (ostream& os, const element &A){
	A.value->output(os);
	return os;
}
