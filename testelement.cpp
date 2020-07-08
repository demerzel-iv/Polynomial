#include "element.h"

using std::cout;
using std::endl;

int main()
{
	element A(12),B(13),C(14);

	printf("begin\n");
	element D=std::move(A);
	A=std::move(B);
	B=std::move(D);
	printf("end\n");

	return 0;
}
