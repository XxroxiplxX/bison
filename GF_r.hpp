#pragma once

#include "iostream"

class GF_r {

    static const int range = 1234576;
    long long load;
    int ex_gcd(int a, int b, int *x, int *y);
public:

    GF_r();
    GF_r(long long load);
    GF_r(const GF_r& GF_r);
    ~GF_r();
    GF_r operator +(const GF_r& g);
    GF_r operator -(const GF_r& g);
    GF_r operator *(const GF_r& g);
    GF_r operator /(const GF_r& g);
    GF_r operator %(const GF_r& g);
    GF_r operator ^(const GF_r& g);
    bool operator ==(const GF_r& g);
    bool operator <(const GF_r& g);
    bool operator <=(const GF_r& g);
    bool operator >=(const GF_r& g);
    bool operator >(const GF_r& g);
    GF_r operator <<(const GF_r& g);
    GF_r operator >>(const GF_r& g);
    GF_r operator <<(int x);
    GF_r operator >>(int x);
    friend std::ostream& operator <<(std::ostream& os, const GF_r& g);
    friend std::istream& operator >>(std::istream& is, const GF_r& g);
    int GF_r_to_int();
    
};

