#include "polynomial.h"

using std::cout;
using std::endl;

void output(element A)
{
	cout<<A<<" type = "<<A.getvalue()->type()<<endl;
}

int main()
{
	cout<<std::fixed<<std::setprecision(4);

	poly A={1,2,3};

	cout<<A<<endl;
	A=-A+1.0;
	cout<<A<<endl;
	A=1-A*2.0;
	cout<<A<<endl;

	return 0;
}
