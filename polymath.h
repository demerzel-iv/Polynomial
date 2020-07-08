#pragma once
#include "polynomial.h"

class polycalc
{
    int n;

public:
    polycalc(int _n):n(_n) {};
    ~polycalc(){}

    void setprecision(int _n) {n = _n;}

    ipoly inv(const ipoly &A); //calc inverse mod x^n
    ipoly ln(const ipoly &A); //calc ln mod x^n
    ipoly exp(const ipoly &A); // calc exp mod x^n
    ipoly pow(const ipoly &A,int k); //calc A^k mod x^n
};