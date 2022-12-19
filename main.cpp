#include "GF.hpp"
#include "GF_r.hpp"
#include <iostream>
int main() {
    //auto g = GF(2)^GF(GF_r(999999999).GF_r_to_int());
    auto g = GF_r(1)/GF_r(2);
    std::cout << g.GF_r_to_int() << std::endl;
    return 0;
}