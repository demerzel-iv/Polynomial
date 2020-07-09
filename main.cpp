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

	//element a(0);
	//output(a*1.0);
	//return 0;

	polyvar& x = polyvar::x;
	polycalc calc(10);

	//poly A=(2*x+1)*(x+1)*(3*x+1)*1.0;
	poly A = {2.3,0.0,1.2,3.234};

	cout<<A<<endl;

	poly B=calc.ln(A);

	cout<<B<<endl;

	//cout<<1 + B + (B^2)*inv((element)2.0) + (B^3)*inv((element)6.0) <<endl;

	cout<<calc.exp(B)<<endl;

	return 0;
}
