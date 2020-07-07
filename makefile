main : polynomial main.cpp 
	g++ main.cpp -o main -O2 -std=c++11
polynomial: polynomial.h ipolynomial.h dpolynomial.h
