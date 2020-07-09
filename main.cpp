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

	element a(2), b(4);

	//element c=std::move(a);
	//a=std::move(b);
	//b=std::move(c);

	std::swap(a,b);

	cout<<a<<" "<<b<<endl;

	output(a*b);

	cout<<"finished"<<endl;

	poly A={1.0,2.0,3.0};
	poly B=A;

	cout<<A<<endl;
	cout<<B<<endl;

	cout<<A*B<<endl;

	return 0;
}
