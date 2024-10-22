/*
    dotProductTest.cpp

    Test program for the dotProduct()
*/

#include <vector>
#include <cassert>
#include "dotProduct.hpp"

// Make sure assert() is not removed
#undef NDEBUG

int main() {

    {
        std::vector<double> v1 = {1, 2, 3};
        std::vector<double> v2 = {4, 5, 6};

        assert(dotProduct(v1, v2) == 32.0);
    }

    return 0;
}
