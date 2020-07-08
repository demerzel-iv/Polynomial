#pragma once
#include "temps.h"
class Int:public temps{
	static const int MOD=998244353;
	static const int g=3;
	int x;
public:
	Int(int X=0):temps(),x(X){}
	int qpow(int v,int y)const{
		int z=1;
		for(;y;y>>=1,v=(long long)v*v%MOD)
			if(y&1)z=(long long)z*v%MOD;
		return z;
	}
	virtual temps* inv()const{
		temps *ret=new Int(qpow(x,MOD-2));
		return ret;
	}
	virtual temps* add(const temps *A,const temps *B)const{
		temps *ret=new Int((((dynamic_cast<const Int*>(A))->x)+((dynamic_cast<const Int*>(B))->x))%MOD);
		return ret;
	}
	virtual temps* substract(const temps *A,const temps *B)const{
		temps *ret=new Int((((dynamic_cast<const Int*>(A))->x)-((dynamic_cast<const Int*>(B))->x)+MOD)%MOD);
		return ret;
	}
	virtual temps* multiply(const temps *A,const temps *B)const{
		temps *ret=new Int((((dynamic_cast<const Int*>(A))->x)*(long long)((dynamic_cast<const Int*>(B))->x))%MOD);
		return ret;
	}
	virtual temps* divide(const temps *A,const temps *B)const{
		temps *ret=new Int((((dynamic_cast<const Int*>(A))->x)*(long long)qpow((dynamic_cast<const Int*>(B))->x,MOD-2))%MOD);
		return ret;
	}
	virtual temps* origin(int times)const{
		temps *ret=new Int(qpow(g,MOD-2));
		return ret;
	}
	virtual temps* v()const{
		return new Int(x);
	}
	virtual void set(double v){
		x=v;
	}
	virtual void set(int v){
		x=v;
	}
	virtual int type()const{
		return typei;
	}
	virtual bool greater(const temps* A,const temps* B)const{
		return ((dynamic_cast<const Int*>(A))->x)>((dynamic_cast<const Int*>(B))->x);
		return 0;
	}
	virtual void output(ostream &os)const{
		os<<x;
	}
};
