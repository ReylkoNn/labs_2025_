#include <iostream>
int main() {
    int number = 0;

    // УСТАНОВКА БИТОВ (сделать бит = 1)
    std::cout << "Setting bits:\n";

    number = number | (1 << 2);  // Установить 2-й бит
    std::cout << "   Set 2nd bit: " << number << std::endl;

    number = number | (1 << 5);  // Установить 5-й бит
    std::cout << "   et 5th bit:" << number << std::endl;

    // ПРОВЕРКА БИТОВ
    std::cout << "\n Checking bits:\n";

    if (number & (1 << 2)) {
        std::cout << "2nd bit = 1" << std::endl;
    }

    if (!(number & (1 << 3))) {
        std::cout << "3rd bit = 0" << std::endl;
    }

    // СБРОС БИТОВ (сделать бит = 0)
    std::cout << "\n Clearing 2nd bit:\n";

    number = number & ~(1 << 2);  // Сбросить 2-й бит
    std::cout << "After clearing 2nd bit: " << number << std::endl;

    // ПЕРЕКЛЮЧЕНИЕ БИТОВ (0→1, 1→0)
    std::cout << "\n Toggling 0th bit:\n";

    number = number ^ (1 << 0);  // Переключить 0-й бит
    std::cout << " After toggling 0th bit: " << number << std::endl;

    // ВЫВОД ВСЕХ БИТОВ
    std::cout << "\n All bits of number " << number << ":\n   ";

    for (int i = 7; i >= 0; i--) {
        if (number & (1 << i)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
}