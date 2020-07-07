#include "polynomial.h"

using std::cout;
using std::endl;

int main()
{
	int s[]={1,2,4,2,1};

	poly A;
	poly B=poly(s,s+4);
	poly C={4,2,3,1};

	cout<<"A: "<<A<<endl;
	cout<<"B: "<<B<<endl;
	cout<<"C: "<<C<<endl;

	return 0;
}
