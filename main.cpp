#include "polynomial.h"

using std::cout;
using std::endl;

int main()
{
	int s[]={1,2,4,2,1};

	poly<int> B=poly<int>(s,s+4);
	poly<int> C=(new polycalc(4))->inv(B);

	cout<<"B: "<<B<<endl;
	cout<<"C: "<<C<<endl;
	cout<<"B*C: "<<B*C<<endl;

	return 0;
}
