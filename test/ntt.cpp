#include<cstdio>
#include<iostream>
using namespace std;
const long long md=998244353;
long long A[400100],B[400100];
long long wn[400100],rwn[400100];
int rev[400100];
long long powd(long long x,int y)
{
	long long res=1;
	while(y)
	{
		if(y&1) res=res*x%md;
		x=x*x%md;
		y>>=1;
	}
	return res;
}
int csh(int n,int m)
{
	int l=1,ws=0;
	while(l<=n+m)
		l<<=1,ws++;
	for(int i=0;i<l;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(ws-1));
	for(int i=0;i<=ws;i++)
	{
		wn[i]=powd(3,(md-1)>>i);
		rwn[i]=powd(wn[i],md-2);
	}
	return l;
}
void NTT(long long *a,int n,int pd)
{
	for(int i=0;i<n;i++)
		if(i<rev[i])
			swap(a[i],a[rev[i]]);
	int id=0;
	long long w,t1,t2;
	for(int l=2;l<=n;l<<=1)
	{
		id++;
		printf("or=%lld ",wn[id]);
		for(int i=0;i<n;i+=l)
		{
			w=1;
			for(int j=i;j<i+(l>>1);j++)
			{
				t1=a[j],t2=a[j+(l>>1)]*w%md;
				a[j]=(t1+t2)%md;
				a[j+(l>>1)]=(t1-t2+md)%md;
				w=w*(pd==1?wn[id]:rwn[id])%md;
			}
		}
		for(int it=0;it<n;it++)
			printf("%lld ",a[it]);
		printf("\n");
	}
	if(pd==-1)
	{
		w=powd(n,md-2);
		for(int i=0;i<n;i++)
			A[i]=A[i]*w%md;
	}
}
void Work(int n)
{
	NTT(A,n,1);
	NTT(B,n,1);
	for(int i=0;i<n;i++){
		A[i]=A[i]*B[i];
	}
	printf("\n");
	NTT(A,n,-1);
}
int main()
{
	freopen("UOJ#34.in","r",stdin);
	int n,m,l;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
		scanf("%lld",&A[i]);
	for(int i=0;i<=m;i++)
		scanf("%lld",&B[i]);
	l=csh(n,m);
	Work(l);
	for(int i=0;i<=n+m;i++)
		printf("%lld ",A[i]);
	printf("\n");
	return 0;
}

