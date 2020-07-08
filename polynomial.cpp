#include "polynomial.h"
#include<bits/stdc++.h>
using namespace std;


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
	s=new element[siz=A.siz];
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

poly::poly(int length,int tp): siz(length),type(tp)
{
	s=new element[siz];
	for(int i=0;i<(int)siz;i++)
	{
		if(type==typed) s[i].setdouble();
		if(type==typei) s[i].setint();
	}
}
poly::poly(const initializer_list<int> &S)
{
	type=typei;
	s=new element[siz=S.size()];
	int i=0;
	for(auto x:S) s[i++].setint(x);
}
poly::poly(const initializer_list<double> &S)
{
	type=typed;
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
	poly ret(max(A.size(),B.size()),A.type);
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=ret[i]+B[i];
	return ret;
}
poly operator - (const poly &A,const poly &B)
{
	poly ret(max(A.size(),B.size()),A.type);
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=ret[i]-B[i];
	return ret;
}
poly operator * (const poly &A,const poly &B)
{
	poly C(A.size()+B.size()-1,A.type);

	int n=1;
	while(n<=(int)C.size())n<<=1;
	element *u=new element[n],*v=new element[n];
	element val0=A[0];
	val0=0;

	if(A.type==typed){
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
		if(A.type==typed)
			C[i].setdouble((dynamic_cast<const Image*>(u[i].getvalue()))->valuer()/n);
		else
			C[i]=u[i]*invn;
	}

	delete [] u;
	delete [] v;

	return C;
}
poly operator * (const poly &A,const int &x)
{
	poly B(A.size(),A.type);
	element v;
	if(A.type==typei) v.setint(x);
	else if(A.type==typed) v.setdouble(x);
	for(int i=0;i<(int)B.size();i++)
		B[i]=A[i]*v;
	return B;
}
poly operator * (const poly &A,const double &x)
{
	poly B(A.size(),A.type);
	element v;
	if(A.type==typei) v.setint(x);
	else if(A.type==typed) v.setdouble(x);
	for(int i=0;i<(int)B.size();i++)
		B[i]=A[i]*v;
	return B;
}
poly operator * (const int &x,const poly &A)
{
	return A*x;
}
poly operator * (const double &x,const poly &A)
{
	return A*x;
}
ostream& operator << (ostream& os,const poly &A)
{
	for(int i=0;i<(int)A.size();i++)
		os<<A[i]<<" ";
	return os;
}
