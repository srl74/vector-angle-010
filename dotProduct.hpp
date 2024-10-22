/*
    dotProduct.hpp

    Include file for function dotProduct()
*/

#ifndef INCLUDED_DOTPRODUCT_HPP
#define INCLUDED_DOTPRODUCT_HPP

#include <vector>

/**
 * The dot product of two vectors
 *
 * The vectors must be non-empty, the same size, and neither can be all 0s
 *
 * @param[in] v1 Left vector
 * @param[in] v2 Right vector
 * @return The dot product of the vectors
 * @retval 0 parameter error
 */
double dotProduct(const std::vector<double>& v1, const std::vector<double>& v2);

#endif
