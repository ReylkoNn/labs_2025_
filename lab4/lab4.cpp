#include <iostream>

int main() {
    int n, count = 0;
    std::cin >> n;

    for (int i = 2; i <= n-2; i++) {
        bool p1 = true, p2 = true;

        for (int j = 2; j < i; j++)
            if (i % j == 0) p1 = false;

        for (int j = 2; j < i+2; j++)
            if ((i+2) % j == 0) p2 = false;

        if (p1 && p2) count++;
    }

    if (count > 0) std::cout << count;
    else std::cout << "No twin primes found";
}