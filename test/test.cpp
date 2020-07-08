#include<bits/stdc++.h>
using namespace std;
class fuck{
	int x;
public:
	virtual void f()const=0;	
};
class ffff:public fuck{
public:
	void f()const{
		printf("fuck\n");
	}
};
void play(const fuck &A){
	A.f();
}
int main(){
	ffff A;
	play(A);
	return 0;
}
