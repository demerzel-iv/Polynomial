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
	int type;

public:

#ifdef _DEBUG
	void debug()
	{
		printf("%d\n",s);

	}
#endif

	unsigned int size() const {return siz;}

	element& operator[] (int i) {return s[i];}
	element operator[](int i) const {return i<(int)siz?s[i]:0;}

	poly(int length,int type);
	poly(const initializer_list<int> &S);
	poly(const initializer_list<double> &S);
	template<typename inputIterator> poly(inputIterator begin,inputIterator end,int tp);

	poly(const poly &A);
	poly(poly &&A);
	poly& operator = (const poly &A);
	poly& operator = (poly &&A);

	~poly(){}

	friend bool operator == (const poly &A,const poly &B);

	friend poly operator + (const poly &A,const poly &B);
	friend poly operator - (const poly &A,const poly &B);
	friend poly operator * (const poly &A,const poly &B);

	friend poly operator * (const poly &A,const int &x);
	friend poly operator * (const int &x,const poly &A);

	friend poly operator * (const poly &A,const double &x);
	friend poly operator * (const double &x,const poly &A);

	friend ostream& operator << (ostream& os,poly &A);
};

bool operator < (const poly &A,const poly &B) = delete; 
bool operator > (const poly &A,const poly &B) = delete;
bool operator <= (const poly &A,const poly &B) = delete;
bool operator >= (const poly &A,const poly &B) = delete;
poly operator + (const poly &A,const int &B) = delete;
poly operator + (const int &A,const poly &B) = delete;
poly operator - (const poly &A,const int &B) = delete;
poly operator - (const int &A,const poly &B) = delete;

