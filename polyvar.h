#pragma once
#include "poly.h"

using std::ostream;

class polyvar
{
    polyvar(){};
public:
    static polyvar x;

    operator poly() const;
};

poly operator ^ (const polyvar &x,int exp);
poly operator + (const polyvar &x,const polyvar &y);
poly operator - (const polyvar &x,const polyvar &y);
poly operator * (const polyvar &x,const polyvar &y);
poly operator / (const polyvar &x,const polyvar &y);

class polyFormatOutputer
{
    const poly &A;

public:
    explicit polyFormatOutputer(const poly &_A) : A(_A) {}

    unsigned int size() const;
    element operator [] (int i) const;
};

ostream &operator<<(ostream &os, const polyFormatOutputer &pfo);
polyFormatOutputer format(const poly &A);