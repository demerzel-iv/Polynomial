CompOpt := g++ -O2 -std=c++11

main : polynomial main.cpp 
	$(CompOpt) main.cpp ipolynomial.o dpolynomial.o -o main 
polynomial: ipolynomial.o dpolynomial.o
ipolynomial.o: ipolynomial.h ipolynomial.cpp
	$(CompOpt) ipolynomial.cpp -o ipolynomial.o -c 
dpolynomial.o: dpolynomial.h dpolynomial.cpp
	$(CompOpt) dpolynomial.cpp -o dpolynomial.o -c 
