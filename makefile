CompOpt = g++ -O2 -std=c++11
objects = ipolynomial.o dpolynomial.o polymath.o

main : $(objects) main.cpp 
	$(CompOpt) main.cpp $(objects) -o main 
ipolynomial.o: ipolynomial.h
dpolynomial.o: dpolynomial.h
polymath.o: polymath.h
