#pragma once
#include<bits/stdc++.h>

using std::ostream;
using std::initializer_list;

using std::swap;
using std::max;

class dpoly
{
	static double qpow(double x,int y);
	static void fft(double *y,int n,int sig); //n should be equal to 2^k 

	unsigned int siz;
	double* s;

public:

#ifdef _DEBUG
	void debug()
	{
		printf("%d\n",s);
	}
#endif

	unsigned int size() const {return siz;}

	double& operator[] (int i) {return s[i];}
	double operator[](int i) const {return i<(int)siz?s[i]:0;}

	dpoly(int length=1);
	dpoly(const initializer_list<double> &S);
	template<typename inputIterator> dpoly(inputIterator begin,inputIterator end);

	dpoly(const dpoly &A);
	dpoly(dpoly &&A);
	dpoly& operator = (const dpoly &A);
	dpoly& operator = (dpoly &&A);

	~dpoly(){}

	friend dpoly operator + (const dpoly &A,const dpoly &B);
	friend dpoly operator - (const dpoly &A,const dpoly &B);
	friend dpoly operator * (const dpoly &A,const dpoly &B);

	friend dpoly operator * (const dpoly &A,const double &x);
	friend dpoly operator * (const double &x,const dpoly &A);

	friend ostream& operator << (ostream& os,dpoly &A);
};

bool operator == (const dpoly &A,const dpoly &B) = delete;
bool operator < (const dpoly &A,const dpoly &B) = delete; 
bool operator > (const dpoly &A,const dpoly &B) = delete;
bool operator <= (const dpoly &A,const dpoly &B) = delete;
bool operator >= (const dpoly &A,const dpoly &B) = delete;
dpoly operator + (const dpoly &A,const int &B) = delete;
dpoly operator + (const int &A,const dpoly &B) = delete;
dpoly operator - (const dpoly &A,const int &B) = delete;
dpoly operator - (const int &A,const dpoly &B) = delete;

template<typename inputIterator> dpoly::dpoly(inputIterator begin,inputIterator end)
{
	siz=end-begin;
	s=new double[siz];
	for(int i=0;i<(int)siz;i++)
		s[i]=*begin,begin++;
}

double dpoly::qpow(double x,int y)
{
	double z=1;
	for(;y;y>>=1,x=(ll)x*x%MOD)
		if(y&1)z=(ll)z*x%MOD;
	return z;
}
int dpoly::inv(int x)
{
	return x==1?x:(-(MOD/x)*(ll)inv(MOD%x)%MOD);
}
void dpoly::ntt(int *y,int n,int sig)
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

dpoly::dpoly(const dpoly &A)
{
#ifdef _DEBUG
	printf("copy construction\n");
#endif
	s=new int[siz=A.siz];
	for(int i=0;i<=(int)siz;i++)
		s[i]=A[i];
}
dpoly::dpoly(dpoly &&A)
{
#ifdef _DEBUG
	printf("move construction\n");
#endif
	s=A.s;
	siz=A.siz;
}
dpoly& dpoly::operator = (const dpoly &A)
{
#ifdef _DEBUG
	printf("copy assignment\n");
#endif
	s=new int[siz=A.siz];
	for(int i=0;i<=(int)siz;i++)
		s[i]=A[i];
	return *this;
}
dpoly& dpoly::operator = (dpoly &&A)
{
#ifdef _DEBUG
	printf("move assignment\n");
#endif
	s=A.s;
	siz=A.siz;
	return *this;
}

dpoly::dpoly(int length):siz(length)
{
	s=new int[siz];
	for(int i=0;i<(int)siz;i++) s[i]=0;
}
dpoly::dpoly(const initializer_list<int> &S)
{
	s=new int[siz=S.size()];
	int i=0;
	for(auto x:S) s[i++] = x;
}

bool operator == (const dpoly &A,const dpoly &B)
{
	if(A.size()!=B.size())return 0;
	for(int i=0;i<(int)A.size();i++)
		if(A[i]!=B[i])return 0;
	return 1;
}
dpoly operator + (const dpoly &A,const dpoly &B)
{
	dpoly ret(max(A.size(),B.size()));
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=((ll)ret[i]+B[i])%MOD;
	return ret;
}
dpoly operator - (const dpoly &A,const dpoly &B)
{
	dpoly ret(max(A.size(),B.size()));
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=((ll)ret[i]-B[i])%MOD;
	return ret;
}
dpoly operator * (const dpoly &A,const dpoly &B)
{
	dpoly C(A.size()+B.size()-1);

	int n=1;
	while(n<=(int)C.size())n<<=1;
	int *u=new int[n],*v=new int[n];

	for(int i=0;i<n;i++)
		u[i]=A[i],v[i]=B[i];

	dpoly::ntt(u,n,1),dpoly::ntt(v,n,1);
	for(int i=0;i<n;i++) u[i]=(ll)u[i]*v[i]%MOD;
	dpoly::ntt(u,n,-1);

	int dn=dpoly::inv(n);
	for(int i=0;i<(int)C.size();i++)
		C[i]=(ll)u[i]*dn%MOD;

	delete [] u;
	delete [] v;

	return C;
}
dpoly operator * (const dpoly &A,const int &x)
{
	dpoly B(A.size());
	for(int i=0;i<(int)B.size();i++)
		B[i]=(ll)A[i]*x%MOD;
	return B;
}
dpoly operator * (const int &x,const dpoly &A)
{
	return A*x;
}
ostream& operator << (ostream& os,dpoly &A)
{
	for(int i=0;i<(int)A.size();i++)
		os<<(A[i]=((A[i]+MOD)%MOD))<<" ";
	return os;
}
