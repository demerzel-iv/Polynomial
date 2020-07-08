#include "polynomial.h"
using std::cout;
using std::endl;
#include<cmath>
using namespace std;
int main(){
	poly A{1.0,1.0,0.0,0.0};
	poly B{1.0,2.0,0.0,0.0};
	poly C=A*B;
	cout<<C<<endl;
	double pi=acos(-1.0);
	cout<<pi<<endl;
	return 0;
}
