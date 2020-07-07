#pragma once
#include<bits/stdc++.h>
#include "element.h"

using std::ostream;
using std::initializer_list;

using std::swap;
using std::max;

typedef poly<int> ipoly;

typedef long long ll;

class poly
{
	static void ntt(int *y,int n,int sig); //n should be equal to 2^k 

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

	int& operator[] (int i) {return s[i];}
	int operator[](int i) const {return i<(int)siz?s[i]:0;}

	poly(int length=1,int tp=0);
	poly(const initializer_list<int> &S);
	poly(const initializer_list<double> &S);
	template<typename inputIterator> poly(inputIterator begin,inputIterator end);

	poly(const ipoly &A);
	poly(ipoly &&A);
	poly& operator = (const ipoly &A);
	poly& operator = (ipoly &&A);

	~poly(){}

	friend bool operator == (const ipoly &A,const ipoly &B);

	friend ipoly operator + (const ipoly &A,const ipoly &B);
	friend ipoly operator - (const ipoly &A,const ipoly &B);
	friend ipoly operator * (const ipoly &A,const ipoly &B);

	friend ipoly operator * (const ipoly &A,const int &x);
	friend ipoly operator * (const int &x,const ipoly &A);

	friend ostream& operator << (ostream& os,ipoly &A);
};

bool operator < (const ipoly &A,const ipoly &B) = delete; 
bool operator > (const ipoly &A,const ipoly &B) = delete;
bool operator <= (const ipoly &A,const ipoly &B) = delete;
bool operator >= (const ipoly &A,const ipoly &B) = delete;
ipoly operator + (const ipoly &A,const int &B) = delete;
ipoly operator + (const int &A,const ipoly &B) = delete;
ipoly operator - (const ipoly &A,const int &B) = delete;
ipoly operator - (const int &A,const ipoly &B) = delete;

