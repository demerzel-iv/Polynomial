#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const double pi=acos(-1.0);
struct node{
	double r,i;
}A[400100],B[400100];
ostream& operator << (ostream &os,const node &x){
	os<<"("<<x.r<<" "<<x.i<<")";
	return os;
}
node operator + (node a,node b){
	return (node){a.r+b.r,a.i+b.i};
}
node operator - (node a,node b){
	return (node){a.r-b.r,a.i-b.i};
}
node operator * (node a,node b){
	return (node){a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r};
}

int rev[400100];
int csh(int n,int m)
{
	int ws=0,l=1;
	while(l<=n+m)
		l<<=1,ws++;
	for(int i=0;i<l;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(ws-1));
	return l;
}
void FFT(node *a,int n,int pd)
{
	for(int i=0;i<n;i++)
		if(rev[i]<i)
			swap(a[rev[i]],a[i]);
	node w,wn,t1,t2;
	for(int l=2;l<=n;l<<=1)
	{
		wn=(node){cos(pd*2*pi/l),sin(pd*2*pi/l)};
		for(int i=0;i<n;i+=l)
		{
			w=(node){1.0,0.0};
			for(int j=i;j<i+(l>>1);j++)
			{
				t1=a[j],t2=a[j+(l>>1)]*w;
				a[j]=t1+t2;
				a[j+(l>>1)]=t1-t2;
				w=w*wn;
			}
		}
		cout<<"omega="<<wn<<" ";
		for(int it=0;it<n;it++)
			cout<<a[it]<<" ";
		cout<<endl;
	}
	if(pd==-1)
	{
		for(int i=0;i<n;i++)
			a[i].r=a[i].r/n;
	}
}
void Work(int n)
{
	FFT(A,n,1);
	FFT(B,n,1);
	for(int i=0;i<n;i++)
		A[i]=A[i]*B[i];
	FFT(A,n,-1);
}
int main()
{
	freopen("UOJ#34.in","r",stdin);
	int n,m,len;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
		scanf("%lf",&A[i].r);
	for(int i=0;i<=m;i++)
		scanf("%lf",&B[i].r);
	len=csh(n,m);
	Work(len);
	for(int i=0;i<=n+m;i++)
		printf("%d ",(int)(A[i].r+0.5));
	return 0;
}

