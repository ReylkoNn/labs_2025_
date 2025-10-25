#include "poly.h"
#include <iostream>
#include <vector>

using namespace Poly;

int main() {
    try {
        int n;
        std::cout << "Enter polynomial degree: ";
        std::cin >> n;

        if (n < 0) {
            std::cout << "Error: degree must be >= 0" << std::endl;
            return 1;
        }

        std::vector<double> coeffs(n + 1);
        std::cout << "Enter coefficients (from constant term to highest): ";
        for (int i = 0; i <= n; i++) {
            if (!(std::cin >> coeffs[i])) {
                std::cout << "Error: invalid input" << std::endl;
                return 1;
            }
        }

        double x;
        std::cout << "Enter point x: ";
        if (!(std::cin >> x)) {
            std::cout << "Error: invalid point" << std::endl;
            return 1;
        }

        std::cout << "\nPolynomial: ";
        print(coeffs);

        double value = calculate(coeffs, x);
        std::cout << "Value at x=" << x << ": " << value << std::endl;

        std::vector<double> deriv = derivative(coeffs);
        std::cout << "Derivative: ";
        print(deriv);

        double deriv_value = calculate(deriv, x);
        std::cout << "Derivative value at x=" << x << ": " << deriv_value << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}