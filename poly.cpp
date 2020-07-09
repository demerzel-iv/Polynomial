#include "poly.h"
#include<bits/stdc++.h>
using namespace std;

int mixtype(int t1,int t2)
{
	if(t1==typed || t2==typed)return typed;
	else return typei;
}

void poly::ntt(element *y,int n,int sig)
{
	static std::vector<int> rev;
	if((int)rev.size()!=n)
	{
		rev.resize(n);
		for(int i=1;i<n;i++)
			rev[i]=(rev[i>>1]>>1)|(i&1?(n>>1):0);
	}
	element tmp;
	for(int i=0;i<n;i++)
		if(rev[i]<i)swap(y[i],y[rev[i]]);

	element *y0,*y1,ny0(y[0]),ny1(y[0]),omega(y[0]),x(y[0]);
	for(int len=2;len<=n;len<<=1)
	{
		omega=omega.origin(len);
		int h=len>>1;
		if(sig==-1) omega=inv(omega);

		for(int p=0;p<n;p+=len)
		{
			y0=y+p,y1=y0+h,x=1;
			for(int i=0;i<h;i++)
			{
				ny0=y0[i]+x*y1[i];
				ny1=y0[i]-x*y1[i];
				y0[i]=ny0,y1[i]=ny1,x=x*omega;
			}
		}
	}
}

poly::poly(const poly&A)
{
#ifdef _DEBUG
	printf("copy construction\n");
#endif
	s=new element[siz=A.siz];
	for(int i=0;i<(int)siz;i++)
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
	s=new element[siz=A.siz];
	for(int i=0;i<(int)siz;i++)
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

poly::poly(int length): siz(length)
{
	s=new element[siz];
}
poly::poly(const initializer_list<int> &S)
{
	s=new element[siz=S.size()];
	int i=0;
	for(auto x:S) s[i++].setint(x);
}
poly::poly(const initializer_list<double> &S)
{
	s=new element[siz=S.size()];
	int i=0;
	for(auto x:S) s[i++].setdouble(x);
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
		ret[i]=ret[i]+B[i];

	if(mixtype(A.type(),B.type()) == typed)
		ret = ret*1.0;
	return ret;
}
poly operator - (const poly &A,const poly &B)
{

	poly ret(max(A.size(),B.size()));
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=ret[i]-B[i];
		
	if(mixtype(A.type(),B.type()) == typed)
		ret = ret*1.0;

	return ret;
}
poly operator * (const poly &A,const poly &B)
{
	if(A.type()!=B.type())return (A*1.0)*(B*1.0);

	poly C(A.size()+B.size()-1);

	int n=1;
	while(n<=(int)C.size())n<<=1;
	element *u=new element[n],*v=new element[n];
	element val0=A[0];
	val0=0;

	if(A.type()==typed){
		for(int i=0;i<n;i++){
			if(i<A.size())
				u[i].setimage((dynamic_cast<const Double*>(A[i].getvalue()))->value(),0);
			else
				u[i].setimage(0);
			if(i<B.size())
				v[i].setimage((dynamic_cast<const Double*>(B[i].getvalue()))->value(),0);
			else
				v[i].setimage(0);
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(i<A.size())
				u[i]=A[i];
			else
				u[i]=val0;
			if(i<B.size())
				v[i]=B[i];
			else
				v[i]=val0;
		}
	}

	poly::ntt(u,n,1);
	poly::ntt(v,n,1);
	for(int i=0;i<n;i++) u[i]=u[i]*v[i];
	poly::ntt(u,n,-1);

	element invn=A[0];
	invn=n;
	invn=inv(invn);
	for(int i=0;i<(int)C.size();i++)
	{
		if(A.type()==typed)
			C[i].setdouble((dynamic_cast<const Image*>(u[i].getvalue()))->valuer()/n);
		else
			C[i]=u[i]*invn;
	}

	delete [] u;
	delete [] v;

	return C;
}
poly operator ^ (const poly &A,int exp)
{
	if(A.size()==1)
	{
		poly ret(1);
		ret[0]=A[0]^exp;
		return ret;
	}
	poly z{1},v(A);
	for(;exp;exp>>=1,v=v*v)
		if(exp&1) z=z*v;
	return z;
}

poly poly::operator - (void) const
{
	return -1*(*this);
}
poly operator+(const poly &A, const element &x)
{
	poly B(A.size());
	B[0]=A[0]+x;
	for(int i=1;i<A.size();i++)
		B[i]=A[i];
	if(B.type()==typed)B=B*1.0;
	return B;
}
poly operator+(const element &x, const poly &A)
{
	return A+x;
}
poly operator - (const poly &A,const element &x)
{
	return A+x*(-1);
}
poly operator - (const element &x,const poly &A)
{
	return x+A*(-1);
}
poly operator * (const poly &A,const element &x)
{
	poly B(A.size());
	for(int i=0;i<A.size();i++)
		B[i]=A[i]*x;
	return B;
}
poly operator * (const element &x,const poly &A)
{
	return A*x;
}
poly operator + (const poly &A,const int &x) { return A+element(x); }
poly operator + (const int &x,const poly &A) { return A+element(x); }
poly operator - (const poly &A,const int &x) { return A-element(x); }
poly operator - (const int &x,const poly &A) { return element(x)-A; }
poly operator * (const poly &A,const int &x) { return A*element(x); }
poly operator * (const int &x,const poly &A) { return A*element(x); }

poly operator + (const poly &A,const double &x) { return A*1.0+element(x); }
poly operator + (const double &x,const poly &A) { return A*1.0+element(x); }
poly operator - (const poly &A,const double &x) { return A*1.0-element(x); }
poly operator - (const double &x,const poly &A) { return element(x)-A*1.0; }
poly operator * (const poly &A,const double &x) { return A*element(x); }
poly operator * (const double &x,const poly &A) { return A*element(x); }

ostream& operator << (ostream& os,const poly &A)
{
	for(int i=0;i<(int)A.size();i++)
		os<<A[i]<<" ";
	return os;
}
