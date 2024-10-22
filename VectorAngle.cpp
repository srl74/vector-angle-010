/*
    VectorAngle.cpp
    The degree angle between two vectors
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include "dotProduct.hpp"

// magnitude of the vector
double magnitude(const std::vector<double>& vector) {
    double sum = 0.0;
    for (double val : vector) {
        sum += val * val;
    }
    return std::sqrt(sum);
}

// convert the string, csv vector into a container
std::vector<double> parseVector(const std::string& input) {
    std::vector<double> result;
    std::stringstream ss(input);
    std::string item;

    while (std::getline(ss, item, ',')) {
        result.push_back(std::stod(item));
    }

    return result;
}

// convert radians to degrees
double radiansToDegrees(double radians) {
    const double DEGREES_PER_RADIAN = 180.0 / M_PI;

    return radians * DEGREES_PER_RADIAN;
}

int main(int argc, char* argv[]) {

    // check for required parameters
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " \"vec1_values\" \"vec2_values\"" << '\n';
        return 1;
    }

    // convert the command-line arguments into containers
    std::vector<double> vector1 = parseVector(argv[1]);
    std::vector<double> vector2 = parseVector(argv[2]);

    // magnitude of vector1
    double vector1Magnitude = magnitude(vector1);
    if (vector1Magnitude == 0.0) {
        std::cerr << "First vector has zero magnitude, cannot compute the angle" << '\n';
        return 1;
    }

    // magnitude of vector2
    double vector2Magnitude = magnitude(vector2);
    if (vector2Magnitude == 0.0) {
        std::cerr << "Second vector has zero magnitude, cannot compute the angle" << '\n';
        return 1;
    }

    // dot product
    double product = dotProduct(vector1, vector2);
    if (product == 0.0) {
        std::cerr << "Unable to calculate the dot product" << '\n';
        return 1;
    }

    // angle in radians
    double cosine = product / (vector1Magnitude * vector2Magnitude);
    cosine = std::clamp(cosine, -1.0, 1.0);
    const double radians = std::acos(cosine);

    // angle in degrees
    const double degrees = radiansToDegrees(radians);

    // output the angle
    std::cout << "Angle: " << degrees << "°" << '\n';

    return 0;
}
