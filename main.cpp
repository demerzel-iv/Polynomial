#include "polynomial.h"

using std::cout;
using std::endl;

void output(element A)
{
	cout<<A<<" type = "<<A.getvalue()->type()<<endl;
}

int main()
{
	cout<<std::fixed<<std::setprecision(2);

	poly x = VARX;

	poly A=(x+1);
	A=A^3;
	poly B{1.0,1.0,0.0,0.0};
	swap(A,B);
	poly C{0,1};
	poly D{0,1};

	cout<<format(x)<<endl;
	cout<<format(A)<<endl;
	cout<<format(B)<<endl;
	cout<<format(A*B)<<endl;
	cout<<format(C*D)<<endl;

	return 0;
}
