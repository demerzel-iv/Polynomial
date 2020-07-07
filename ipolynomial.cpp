#include "ipolynomial.h"

int ipoly::qpow(int x,int y)
{
	int z=1;
	for(;y;y>>=1,x=(ll)x*x%MOD)
		if(y&1)z=(ll)z*x%MOD;
	return z;
}
int ipoly::inv(int x)
{
	return x==1?x:(-(MOD/x)*(ll)inv(MOD%x)%MOD);
}
void ipoly::ntt(int *y,int n,int sig)
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

ipoly::poly(const ipoly&A)
{
#ifdef _DEBUG
	printf("copy construction\n");
#endif
	s=new int[siz=A.siz];
	for(int i=0;i<=(int)siz;i++)
		s[i]=A[i];
}
ipoly::poly(ipoly &&A)
{
#ifdef _DEBUG
	printf("move construction\n");
#endif
	s=A.s;
	siz=A.siz;
}
ipoly& ipoly::operator = (const ipoly &A)
{
#ifdef _DEBUG
	printf("copy assignment\n");
#endif
	s=new int[siz=A.siz];
	for(int i=0;i<=(int)siz;i++)
		s[i]=A[i];
	return *this;
}
ipoly& ipoly::operator = (ipoly &&A)
{
#ifdef _DEBUG
	printf("move assignment\n");
#endif
	s=A.s;
	siz=A.siz;
	return *this;
}

ipoly::poly(int length):siz(length)
{
	s=new int[siz];
	for(int i=0;i<(int)siz;i++) s[i]=0;
}
ipoly::poly(const initializer_list<int> &S)
{
	s=new int[siz=S.size()];
	int i=0;
	for(auto x:S) s[i++] = x;
}

bool operator == (const ipoly &A,const ipoly &B)
{
	if(A.size()!=B.size())return 0;
	for(int i=0;i<(int)A.size();i++)
		if(A[i]!=B[i])return 0;
	return 1;
}
ipoly operator + (const ipoly &A,const ipoly &B)
{
	ipoly ret(max(A.size(),B.size()));
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=((ll)ret[i]+B[i])%MOD;
	return ret;
}
ipoly operator - (const ipoly &A,const ipoly &B)
{
	ipoly ret(max(A.size(),B.size()));
	for(int i=0;i<(int)A.size();i++)
		ret[i]=A[i];
	for(int i=0;i<(int)B.size();i++)
		ret[i]=((ll)ret[i]-B[i])%MOD;
	return ret;
}
ipoly operator * (const ipoly &A,const ipoly &B)
{
	ipoly C(A.size()+B.size()-1);

	int n=1;
	while(n<=(int)C.size())n<<=1;
	int *u=new int[n],*v=new int[n];

	for(int i=0;i<n;i++)
		u[i]=A[i],v[i]=B[i];

	ipoly::ntt(u,n,1),ipoly::ntt(v,n,1);
	for(int i=0;i<n;i++) u[i]=(ll)u[i]*v[i]%MOD;
	ipoly::ntt(u,n,-1);

	int dn=ipoly::inv(n);
	for(int i=0;i<(int)C.size();i++)
		C[i]=(ll)u[i]*dn%MOD;

	delete [] u;
	delete [] v;

	return C;
}
ipoly operator * (const ipoly &A,const int &x)
{
	ipoly B(A.size());
	for(int i=0;i<(int)B.size();i++)
		B[i]=(ll)A[i]*x%MOD;
	return B;
}
ipoly operator * (const int &x,const ipoly &A)
{
	return A*x;
}
ostream& operator << (ostream& os,ipoly &A)
{
	for(int i=0;i<(int)A.size();i++)
		os<<(A[i]=((A[i]+MOD)%MOD))<<" ";
	return os;
}