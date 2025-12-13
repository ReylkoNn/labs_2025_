#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

namespace strutils {

    // Рекурсивно считает количество вхождений символа в строку
    int countChar(const std::string& str, char c, size_t pos = 0);

    // Рекурсивно проверяет, является ли строка палиндромом
    bool isPalindrome(const std::string& str, size_t start = 0, size_t end = std::string::npos);

    // Рекурсивно ищет первое вхождение подстроки (возвращает позицию или -1)
    int findSubstring(const std::string& text, const std::string& sub, size_t pos = 0);

    // Рекурсивно переворачивает строку
    std::string reverseString(const std::string& str, size_t pos = 0);

} // namespace strutils

#endif // STRING_UTILS_H