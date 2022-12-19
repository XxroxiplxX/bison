#include "GF.hpp"


GF::GF() :load(0) {

}

GF::GF(long long int load) {
    if (load < 0) {
        this->load = load%range + range;
    } else {
        this->load = load%range;
    }
}

GF::GF(const GF &gf) {
    if (gf.load < 0) {
        this->load = gf.load%range + range;
    } else {
        this->load = gf.load%range;
    }
}

GF::~GF() {
    //std::cout << "deleted" << std::endl;
}

GF GF::operator+(const GF &g) {
    return GF((this->load + g.load)%range);
}

GF GF::operator-(const GF &g) {
    int r = (this->load - g.load)%range;
    if (r < 0) {
        r += range;
    }
    return GF(r);
}

GF GF::operator*(const GF &g) {
    return GF((this->load * g.load)%range);
}

GF GF::operator/(const GF &g) {
    if (g.load == 0) {
        throw "division by zero";
    }
    int g_copy = g.load;
    int x,y;
    int gcd = ex_gcd(g.load, range, &x, &y);
    if (gcd == 1) { //x == g^-1
        return GF((this->load*x)%range);
    } else {
        throw "divisor not inversible";
    }

    
}

GF GF::operator^(const GF &g) {
    if (g.load == 0) {
        return GF(1);
    }
    if (this->load == 0) {
        return GF();
    }
    auto cp_of_this = GF(this->load);
    auto cp_of_g = GF(g.load);
    auto result = GF(1);
    while (cp_of_g.load > 0) {
        if (cp_of_g.load%2 == 1) {
           result = result * cp_of_this;
        }
        cp_of_this = cp_of_this*cp_of_this;
        cp_of_g = cp_of_g >> 1;
    }
    return result;
}

bool GF::operator==(const GF &g) {
    if (this->load == g.load) {
        return 1;
    } else {
        return false;
    }
}

bool GF::operator<(const GF &g) {
    if (this->load < g.load) {
        return 1;
    } else {
        return false;
    }
}

bool GF::operator<=(const GF &g) {
    if (this->load <= g.load) {
        return 1;
    } else {
        return false;
    }
}

bool GF::operator>=(const GF &g) {
    if (this->load >= g.load) {
        return 1;
    } else {
        return false;
    }
}

bool GF::operator>(const GF &g) {
    if (this->load > g.load) {
        return 1;
    } else {
        return false;
    }
}

GF GF::operator<<(const GF &g) {
    return GF((this->load << g.load)%range);
}

GF GF::operator>>(const GF &g) {
    return GF((this->load >> g.load)%range);
}

int GF::GF_to_int() {
    return this->load;
}

GF GF::operator%(const GF &g) {
    if (g.load == 0) {
        throw "division by zero";
    }
    return GF(this->load%g.load);
}

GF GF::operator<<(int x) {
    return GF((this->load << x)%range);
}

GF GF::operator>>(int x) {
    return GF((this->load >> x)%range);
}

std::ostream &operator<<(std::ostream &os, const GF &g) {
    os << g.load;
    return os;
}
std::istream  &operator>>(std::istream &is, const GF &g) {
    is >> g.load;
    return is;
}

int GF::ex_gcd(int a, int b, int *x, int *y) {
    
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