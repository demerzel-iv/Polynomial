#pragma once
#include<bits/stdc++.h>

using std::ostream;
using std::initializer_list;

using std::swap;
using std::max;

typedef long long ll;
const int MOD = 998244353; //should be suitable for NTT;

class poly
{
	static int qpow(int x,int y);
	static int inv(int x);
	static void ntt(int *y,int n,int sig); //n should be equal to 2^k 

	unsigned int siz;
	int* s;

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

	poly(int length=1);
	poly(const initializer_list<int> &S);
	template<typename inputIterator> poly(inputIterator begin,inputIterator end);

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

template<typename inputIterator> poly::poly(inputIterator begin,inputIterator end)
{
	siz=end-begin;
	s=new int[siz];
	for(int i=0;i<(int)siz;i++)
		s[i]=*begin,begin++;
}

int poly::qpow(int x,int y)
{
	int z=1;
	for(;y;y>>=1,x=(ll)x*x%MOD)
		if(y&1)z=(ll)z*x%MOD;
	return z;
}
int poly::inv(int x)
{
	return x==1?x:(-(MOD/x)*(ll)inv(MOD%x)%MOD);
}
void poly::ntt(int *y,int n,int sig)
{
	static std::vector<int> rev;
	if((int)rev.size()!=n)
	{
		rev.resize(n);
		for(int i=1;i<n;i++)
			rev[i]=(rev[i>>1]>>1)|(i&1?(n>>1):0);
	}
	for(int i=0;i<n;i++)
		if(rev[i]<i)swap(y[i],y[rev[i]]);

	int *y0,*y1,ny0,ny1;
	for(int len=2;len<=n;len<<=1)
	{
		int omega = qpow(3,(MOD-1)/len), h=len>>1 ,x;
		if(sig==-1)omega=inv(omega);

		for(int p=0;p<n;p+=len)
		{
			y0=y+p,y1=y0+h,x=1;
			for(int i=0;i<h;i++)
			{
				ny0=(y0[i]+(ll)x*y1[i])%MOD;
				ny1=(y0[i]-(ll)x*y1[i])%MOD;
				y0[i]=ny0,y1[i]=ny1,x=(ll)x*omega%MOD;
			}
		}
	}
}

poly::poly(const poly &A)
{
#ifdef _DEBUG
	printf("copy construction\n");
#endif
	s=new int[siz=A.siz];
	for(int i=0;i<=(int)siz;i++)
		s[i]=A[i];
}
poly::poly(poly &&A)
{
#ifdef _DEBUG
	printf("move construction\n");
#endif
	s=A.s;
	siz=A.siz;
}
poly& poly::operator = (const poly &A)
{
#ifdef _DEBUG
	printf("copy assignment\n");
#endif
	s=new int[siz=A.siz];
	for(int i=0;i<=(int)siz;i++)
		s[i]=A[i];
	return *this;
}
poly& poly::operator = (poly &&A)
{
#ifdef _DEBUG
	printf("move assignment\n");
#endif
	s=A.s;
	siz=A.siz;
	return *this;
}

poly::poly(int length):siz(length)
{
	s=new int[siz];
	for(int i=0;i<(int)siz;i++) s[i]=0;
}
poly::poly(const initializer_list<int> &S)
{
	s=new int[siz=S.size()];
	int i=0;
	for(auto x:S) s[i++] = x;
}

bool operator == (const poly &A,const poly &B)
{
	if(A.size()!=B.size())return 0;
	for(int i=0;i<(int)A.size();i++)
		if(A[i]!=B[i])return 0;
	return 1;
}
poly operator + (const poly &A,const poly &B)
{
	poly ret(max(A.size(),B.size()));
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=((ll)ret[i]+B[i])%MOD;
	return ret;
}
poly operator - (const poly &A,const poly &B)
{
	poly ret(max(A.size(),B.size()));
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=((ll)ret[i]-B[i])%MOD;
	return ret;
}
poly operator * (const poly &A,const poly &B)
{
	poly C(A.size()+B.size()-1);

	int n=1;
	while(n<=(int)C.size())n<<=1;
	int *u=new int[n],*v=new int[n];

	for(int i=0;i<n;i++)
		u[i]=A[i],v[i]=B[i];

	poly::ntt(u,n,1),poly::ntt(v,n,1);
	for(int i=0;i<n;i++) u[i]=(ll)u[i]*v[i]%MOD;
	poly::ntt(u,n,-1);

	int dn=poly::inv(n);
	for(int i=0;i<(int)C.size();i++)
		C[i]=(ll)u[i]*dn%MOD;

	delete [] u;
	delete [] v;

	return C;
}
poly operator * (const poly &A,const int &x)
{
	poly B(A.size());
	for(int i=0;i<(int)B.size();i++)
		B[i]=(ll)A[i]*x%MOD;
	return B;
}
poly operator * (const int &x,const poly &A)
{
	return A*x;
}
ostream& operator << (ostream& os,poly &A)
{
	for(int i=0;i<(int)A.size();i++)
		os<<(A[i]=((A[i]+MOD)%MOD))<<" ";
	return os;
}
