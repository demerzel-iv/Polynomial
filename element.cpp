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
element inv(const element &A){
	return element(A.value->inv());
}


ostream& operator << (ostream& os, const element &A){
	A.value->output(os);
	return os;
}
