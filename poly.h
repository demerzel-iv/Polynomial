#pragma once
#include<bits/stdc++.h>
#include "element.h"

using std::ostream;
using std::initializer_list;

using std::swap;
using std::max;

typedef long long ll;

class poly
{
	static void ntt(element *y,int n,int sig); //n should be equal to 2^k 

	unsigned int siz;
	element* s;

public:

#ifdef _DEBUG
	void debug()
	{
		printf("%d\n",s);

	}
#endif

	unsigned int size() const {return siz;}

	element& operator[] (int i) {return s[i];}
	element operator[](int i) const {return i<(int)siz?s[i]: (type()==typei?element((int)0):element(0.0));}

	explicit poly(int length=0);
	poly(const initializer_list<int> &S);
	poly(const initializer_list<double> &S);
	template<typename inputIterator> poly(inputIterator begin,inputIterator end,int type=typei);

	poly(const poly &A);
	poly(poly &&A);
	poly& operator = (const poly &A);
	poly& operator = (poly &&A);

	~poly(){}

	int type()const {return siz==0? typei : s[0].type();}

	poly operator-(void) const;

	friend poly operator * (const poly &A, const poly &B);
	friend poly operator / (const poly &A, const poly &B); 
	friend poly operator % (const poly &A, const poly &B); 
};

bool operator==(const poly &A, const poly &B);

poly operator + (const poly &A, const poly &B);
poly operator - (const poly &A, const poly &B);
poly operator * (const poly &A, const poly &B);
poly operator / (const poly &A, const poly &B); 
poly operator % (const poly &A, const poly &B);
poly operator ^ (const poly &A, int exp);

ostream &operator<<(ostream &os, const poly &A);

poly operator + (const poly &A, const element &x);
poly operator + (const element &x, const poly &A);
poly operator - (const poly &A,const element &x);
poly operator - (const element &x,const poly &A);
poly operator * (const poly &A, const element &x);
poly operator * (const element &x, const poly &A);
poly operator / (const poly &A, const element &x);

poly operator + (const poly &A,const int &x);
poly operator + (const int &x,const poly &A);
poly operator - (const poly &A,const int &x);
poly operator - (const int &x,const poly &A);
poly operator * (const poly &A,const int &x);
poly operator * (const int &x,const poly &A);
poly operator / (const poly &A,const int &x);

poly operator + (const poly &A,const double &x);
poly operator + (const double &x,const poly &A);
poly operator - (const poly &A,const double &x);
poly operator - (const double &x,const poly &A);
poly operator * (const poly &A,const double &x);
poly operator * (const double &x,const poly &A);
poly operator / (const poly &A,const double &x);

bool operator < (const poly &A,const poly &B) = delete; 
bool operator > (const poly &A,const poly &B) = delete;
bool operator <= (const poly &A,const poly &B) = delete;
bool operator >= (const poly &A,const poly &B) = delete;


template<typename inputIterator> poly::poly(inputIterator begin,inputIterator end,int tp) //类的template成员函数的实现必须放在同一文件中
{
	siz=end-begin;
	s=new element[siz];
	for(int i=0;i<(int)siz;i++){
		if(type()==typed) s[i].setdouble(*begin);
		else if(type()==typei) s[i].setint(*begin);
		begin++;
	}
}
const poly VARX{0,1};
