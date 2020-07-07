#pragma once
#include<bits/stdc++.h>
#include "templatepoly.h"

using std::ostream;
using std::initializer_list;

using std::swap;
using std::max;

typedef poly<int> ipoly;

typedef long long ll;
const int MOD = 998244353; //should be suitable for NTT;

template<> class poly<int>
{
	static void ntt(int *y,int n,int sig); //n should be equal to 2^k 

	unsigned int siz;
	int* s;

public:

	static int qpow(int x,int y);
	static int inv(int x);

#ifdef _DEBUG
	void debug()
	{
		printf("%d\n",s);
	}
#endif

	unsigned int size() const {return siz;}

	int& operator[] (int i) {return s[i];}
	int operator[](int i) const {return i<(int)siz?s[i]:0;}

	poly(int length=1);
	poly(const initializer_list<int> &S);
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

	friend ostream& operator << (ostream& os,const ipoly &A);
};

bool operator < (const ipoly &A,const ipoly &B) = delete; 
bool operator > (const ipoly &A,const ipoly &B) = delete;
bool operator <= (const ipoly &A,const ipoly &B) = delete;
bool operator >= (const ipoly &A,const ipoly &B) = delete;
ipoly operator + (const ipoly &A,const int &B) = delete;
ipoly operator + (const int &A,const ipoly &B) = delete;
ipoly operator - (const ipoly &A,const int &B) = delete;
ipoly operator - (const int &A,const ipoly &B) = delete;

template<typename inputIterator> ipoly::poly(inputIterator begin,inputIterator end)
{
	siz=end-begin;
	s=new int[siz];
	for(int i=0;i<(int)siz;i++)
		s[i]=*begin,begin++;
}