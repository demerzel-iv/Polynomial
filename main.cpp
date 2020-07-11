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

	poly A = x^20, B = x-2;


	cout<< format(A / B) <<endl;
	cout<< format(A % B) << endl;

	return 0;
}
