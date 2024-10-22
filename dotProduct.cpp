/*
    dotProduct.hpp

    Include file for function dotProduct()
*/

#include "dotProduct.hpp"
#include <algorithm>

/**
 * The dot product of two vectors
 *
 * The vectors must be non-empty, the same size, and neither can be all 0s
 *
 * @param[in] v1 Left vector
 * @param[in] v2 Right vector
 * @return The dot product of v1 and v2
 * @retval 0 parameter error
 */
double dotProduct(const std::vector<double>& v1, const std::vector<double>& v2) {

    // precondition: both vector lengths are the same
    if (v1.size() != v2.size()) {
        return 0.0;
    }

    // precondition: first vector is not empty
    if (v1.empty()) {
        return 0.0;
    }

    // precondition: second vector is not empty
    if (v2.empty()) {
        return 0.0;
    }

    // precondition: first vector is not all zeroes
    const auto nonZeroPositionV1 = std::find_if(v1.begin(), v1.end(), [](double x){ return x != 0; });
    if (nonZeroPositionV1 == v1.end()) {
        return 0.0;
    }

    // precondition: second vector is not all zeroes
    const auto nonZeroPositionV2 = std::find_if(v2.begin(), v2.end(), [](double x){ return x != 0; });
    if (nonZeroPositionV2 == v2.end()) {
        return 0.0;
    }

    // dot product of the two vectors
    double result = 0.0;
    std::vector<double>::size_type i = 0;
    while (i < v1.size()) {
        result += v1[i] * v2[i];
        ++i;
    }

    return result;
}
