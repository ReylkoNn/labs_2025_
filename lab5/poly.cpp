#include "poly.h"
#include <iostream>
#include <stdexcept>

namespace Poly {

    double calculate(const std::vector<double>& coeffs, double x) {
        if (coeffs.empty()) {
            throw std::invalid_argument("No coefficients");
        }

        double result = 0;
        double power = 1;

        for (double c : coeffs) {
            result += c * power;
            power *= x;
        }

        return result;
    }

    std::vector<double> derivative(const std::vector<double>& coeffs) {
        if (coeffs.size() <= 1) {
            return {0};
        }

        std::vector<double> result;
        for (int i = 1; i < coeffs.size(); i++) {
            result.push_back(coeffs[i] * i);
        }

        return result;
    }

    void print(const std::vector<double>& coeffs) {
        for (int i = 0; i < coeffs.size(); i++) {
            if (i > 0) std::cout << " + ";
            std::cout << coeffs[i];
            if (i > 0) std::cout << "*x";
            if (i > 1) std::cout << "^" << i;
        }
        std::cout << std::endl;
    }

}