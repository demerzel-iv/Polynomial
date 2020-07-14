#include "polynomial.h"
#include <bits/stdc++.h>

using std::cout;
using std::endl;

void output(element A)
{
	cout<<A<<" type = "<<A.getvalue()->type()<<endl;
}
int rd(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int main()
{
	srand(time(0));
	cout<<std::fixed<<std::setprecision(2);

	polyvar& x = polyvar::x;
	polycalc calc(10);

	poly A = {1.0,2.0,3.0};
	poly B = {1,2,3};

	cout<<A/2<<endl;
	cout<<B/2<<endl;

	return 0;
}
