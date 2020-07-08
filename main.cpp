#include "polynomial.h"

using std::cout;
using std::endl;

void test1()
{
	int s[]={1,1,4,2,1};

	poly A=poly(s+1,s+4,typed);
	poly B=-1*A;
	printf("E\n");
	B[0]=B[0]+1.0;

	printf("A\n");

	poly C(1,typed),D(1,typed);
	C[0]=0,D[0]=1;
	printf("B\n");
	for(int i=1;i<=5;i++)
	{
		C=C+D;
		D=D*B;

		cout<<"i = "<<i<<", D = "<<D<<endl;
	}

	cout<<A<<endl;
	cout<<B<<endl;
	cout<<C<<endl;
	cout<<A*C<<endl;

}

void output(element A)
{
	cout<<A<<" type = "<<A.getvalue()->type()<<endl;
}

int main()
{
	polycalc *calc=new polycalc(10);

	poly B = {1,2,0,0};
	poly C = calc->inverse(B);

	cout<<"B: "<<B<<endl;
	cout<<"C: "<<C<<endl;
	cout<<"B*C: "<<B*C<<endl;

	return 0;
}
