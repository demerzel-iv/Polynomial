#include "polynomial.h"

using std::cout;
using std::endl;

int main()
{
	int s[]={1,2,4,2,1};

	poly<int> A;
	poly<int> B=poly<int>(s,s+4);
	poly<int> C={4,2,3,1};

	cout<<"A: "<<A<<endl;
	cout<<"B: "<<B<<endl;
	cout<<"C: "<<C<<endl;

	return 0;
}
