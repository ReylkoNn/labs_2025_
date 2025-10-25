#ifndef POLY_H
#define POLY_H

#include <vector>

namespace Poly {
    double calculate(const std::vector<double>& coeffs, double x);
    std::vector<double> derivative(const std::vector<double>& coeffs);
    void print(const std::vector<double>& coeffs);
}

#endif