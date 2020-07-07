#include "temps.h"
class Int:public temps{
	static const int MOD=998244353;
	static const int g=3;
public:
	int x;
	int qpow(int x,int y){
		int z=1;
		for(;y;y>>=1,x=(long long)x*x%MOD)
			if(y&1)z=(long long)z*x%MOD;
		return z;
	}
	virtual temps* inv()const{
		temps ret=new Int(powd(x,MOD-2));
		return ret;
	}
	virtual temps* add(const *temps A,const *temps B)const{
		temps ret=new Int((((dynamic_cast<Int*>A)->x)+((dynamic_cast<Int*>A)->x))%MOD);
		return ret;
	}
	virtual temps* substract(const *temps A,const *temps B)const{
		temps ret=new Int((((dynamic_cast<Int*>A)->x)-((dynamic_cast<Int*>A)->x)+MOD)%MOD);
		return ret;
	}
	virtual temps* multiply(const *temps A,const *temps B)const{
		temps ret=new Int((((dynamic_cast<Int*>A)->x)*(long long)((dynamic_cast<Int*>A)->x))%MOD);
		return ret;
	}
	virtual temps* divide(const *temps A,const *temps B)const{
		temps ret=new Int((((dynamic_cast<Int*>A)->x)*(long long)powd((dynamic_cast<Int*>A)->x,MOD-2))%MOD);
		return ret;
	}
	virtual temps* v(){
		return new Int(x);
	}
}
