#pragma once

#include "iostream"

class GF {

    static const int range = 1234577;
    long long load;
    int ex_gcd(int a, int b, int *x, int *y);
public:

    GF();
    GF(long long load);
    GF(const GF& gf);
    ~GF();
    GF operator +(const GF& g);
    GF operator -(const GF& g);
    GF operator *(const GF& g);
    GF operator /(const GF& g);
    GF operator %(const GF& g);
    GF operator ^(const GF& g);
    bool operator ==(const GF& g);
    bool operator <(const GF& g);
    bool operator <=(const GF& g);
    bool operator >=(const GF& g);
    bool operator >(const GF& g);
    GF operator <<(const GF& g);
    GF operator >>(const GF& g);
    GF operator <<(int x);
    GF operator >>(int x);
    friend std::ostream& operator <<(std::ostream& os, const GF& g);
    friend std::istream& operator >>(std::istream& is, const GF& g);
    int GF_to_int();
    
};

