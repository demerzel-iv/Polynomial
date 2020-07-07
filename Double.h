#include "temps.h"
class Double:public temps{
public:
	double x;
	virtual temps* inv()const{
		temps ret=new Double(1.0/x);
		return ret;
	}
	virtual temps* add(const *temps A,const *temps B)const{
		temps ret=new Double(((dynamic_cast<Double*>A)->x)+((dynamic_cast<Double*>A)->x));
		return ret;
	}
	virtual temps* substract(const *temps A,const *temps B)const{
		temps ret=new Double(((dynamic_cast<Double*>A)->x)-((dynamic_cast<Double*>A)->x));
		return ret;
	}
	virtual temps* multiply(const *temps A,const *temps B)const{
		temps ret=new Double(((dynamic_cast<Double*>A)->x)*((dynamic_cast<Double*>A)->x));
		return ret;
	}
	virtual temps* divide(const *temps A,const *temps B)const{
		temps ret=new Double(((dynamic_cast<Double*>A)->x)/((dynamic_cast<Double*>A)->x));
		return ret;
	}
	virtual temps* v(){
		return new Double(x);
	}
}
