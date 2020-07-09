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

	poly A = (x^2) - 2.0*x + 1 ;

	cout<<format(A)<<endl;
	cout<<format(A*A)<<endl;

	cout<<x+x<<endl;

//cout<<A<<endl;
	//cout<<A*A<<endl;

	return 0;
}
