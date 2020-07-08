#pragma once
#include "poly.h"

class polycalc
{
    int n;

public:
    polycalc(int _n):n(_n) {};
    ~polycalc(){}

    void setprecision(int _n) {n = _n;}

    poly inverse(const poly &A); //calc inverse mod x^n
    poly ln(const poly &A); //calc ln mod x^n
    poly exp(const poly &A); // calc exp mod x^n
    poly pow(const poly &A,int k); //calc A^k mod x^n
};