#include "GF_r.hpp"


GF_r::GF_r() :load(0) {

}

GF_r::GF_r(long long int load) {
    if (load < 0) {
        this->load = load%range + range;
    } else {
        this->load = load%range;
    }
}

GF_r::GF_r(const GF_r &GF_r) {
    if (GF_r.load < 0) {
        this->load = GF_r.load%range + range;
    } else {
        this->load = GF_r.load%range;
    }
}

GF_r::~GF_r() {
    //std::cout << "deleted" << std::endl;
}

GF_r GF_r::operator+(const GF_r &g) {
    return GF_r((this->load + g.load)%range);
}

GF_r GF_r::operator-(const GF_r &g) {
    int r = (this->load - g.load)%range;
    if (r < 0) {
        r += range;
    }
    return GF_r(r);
}

GF_r GF_r::operator*(const GF_r &g) {
    return GF_r((this->load * g.load)%range);
}

GF_r GF_r::operator/(const GF_r &g) {
    if (g.load == 0) {
        throw "division by zero";
    }
    int g_copy = g.load;
    int x,y;
    int gcd = ex_gcd(g.load, range, &x, &y);
    if (gcd == 1) { //x == g^-1
        return GF_r((this->load*x)%range);
    } else {

        throw "divisor not inversible";
    }

    
}

GF_r GF_r::operator^(const GF_r &g) {
    if (g.load == 0) {
        return GF_r(1);
    }
    if (this->load == 0) {
        return GF_r();
    }
    auto cp_of_this = GF_r(this->load);
    auto cp_of_g = GF_r(g.load);
    auto result = GF_r(1);
    while (cp_of_g.load > 0) {
        if (cp_of_g.load%2 == 1) {
           result = result * cp_of_this;
        }
        cp_of_this = cp_of_this*cp_of_this;
        cp_of_g = cp_of_g >> 1;
    }
    return result;
}

bool GF_r::operator==(const GF_r &g) {
    if (this->load == g.load) {
        return 1;
    } else {
        return false;
    }
}

bool GF_r::operator<(const GF_r &g) {
    if (this->load < g.load) {
        return 1;
    } else {
        return false;
    }
}

bool GF_r::operator<=(const GF_r &g) {
    if (this->load <= g.load) {
        return 1;
    } else {
        return false;
    }
}

bool GF_r::operator>=(const GF_r &g) {
    if (this->load >= g.load) {
        return 1;
    } else {
        return false;
    }
}

bool GF_r::operator>(const GF_r &g) {
    if (this->load > g.load) {
        return 1;
    } else {
        return false;
    }
}

GF_r GF_r::operator<<(const GF_r &g) {
    return GF_r((this->load << g.load)%range);
}

GF_r GF_r::operator>>(const GF_r &g) {
    return GF_r((this->load >> g.load)%range);
}

int GF_r::GF_r_to_int() {
    return this->load;
}

GF_r GF_r::operator%(const GF_r &g) {
    if (g.load == 0) {
        throw "division by zero";
    }
    return GF_r(this->load%g.load);
}

GF_r GF_r::operator<<(int x) {
    return GF_r((this->load << x)%range);
}

GF_r GF_r::operator>>(int x) {
    return GF_r((this->load >> x)%range);
}

std::ostream &operator<<(std::ostream &os, const GF_r &g) {
    os << g.load;
    return os;
}
std::istream  &operator>>(std::istream &is, const GF_r &g) {
    is >> g.load;
    return is;
}

int GF_r::ex_gcd(int a, int b, int *x, int *y) {
    
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = ex_gcd(b%a, a, &x1, &y1);
 
    // Update x and y using results of
    // recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}