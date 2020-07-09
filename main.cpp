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

	polyvar& x = polyvar::x;

	poly A=(x+2)*(x+1);
	poly B{1.0,1.0,0.0,0.0};

	cout<<format(A)<<endl;
	cout<<format(B)<<endl;
	cout<<format(A*B)<<endl;

	return 0;
}
