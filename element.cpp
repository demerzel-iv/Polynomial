#include "element.h"
using namespace std;
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
	return element(A.value->divide(A.value,B.value));
}
bool operator < (const element &A,const element &B){
	return A.value->greater(B.value,A.value);
}
bool operator > (const element &A,const element &B){
	return A.value->greater(A.value,B.value);
}
bool operator <= (const element &A,const element &B){
	return !(A.value->greater(A.value,B.value));
}
bool operator >= (const element &A,const element &B){
	return !(A.value->greater(B.value,A.value));
}
bool operator == (const element &A,const element &B){
	return !((A.value->greater(A.value,B.value))&&(A.value->greater(B.value,A.value)));
}
bool operator != (const element &A,const element &B){
	return (A.value->greater(A.value,B.value))&&(A.value->greater(B.value,A.value));
}


element inv(const element &A){return element(A.value->inv());}

element element::origin(int times){return element(value->origin(times));}

void element::setint(int x){value=static_cast<temps*>(new Int(x));}
void element::setdouble(double x){value=static_cast<temps*>(new Double(x));}
void element::setimage(double r,double i){value=static_cast<temps*>(new Image(r,i));}

temps* element::getvalue(){return value;}

ostream& operator << (ostream& os, const element &A){
	A.value->output(os);
	return os;
}
