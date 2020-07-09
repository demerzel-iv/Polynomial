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

<<<<<<< HEAD
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
=======
	polyvar& x = polyvar::x;
	polycalc calc(4);

	cout<<x*x<<endl;
	cout<<x/x<<endl;
	cout<<x-x<<endl;

	poly A=(x+2)*(x+1);
	poly B{1.0,1.0,0.0,3.0};

	cout <<A<<endl;
	cout<<calc.intgration(A)<<endl;
	cout<<calc.derivative(A)<<endl;

	cout<<calc.intgration(calc.derivative(A))<<endl;
	cout<<calc.derivative(calc.intgration(A))<<endl;

	cout<<format(B)<<endl;
	cout<<format(calc.intgration(B))<<endl;
	cout<<format(calc.derivative(B))<<endl;
>>>>>>> d5116568daf0c96e360306f568003ad94c31c791

	return 0;
}
