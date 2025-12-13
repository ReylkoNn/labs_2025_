#include "StringUtils.h"
#include <algorithm>

namespace strutils {

    int countChar(const std::string& str, char c, size_t pos) {
        // Базовый случай: конец строки
        if (pos >= str.length()) return 0;
        // Считаем текущий символ + рекурсивный вызов для остатка
        return (str[pos] == c ? 1 : 0) + countChar(str, c, pos + 1);
    }

    bool isPalindrome(const std::string& str, size_t start, size_t end) {
        // Устанавливаем конец при первом вызове
        if (end == std::string::npos) end = str.length() - 1;
        // Базовый случай: указатели встретились или пересеклись
        if (start >= end) return true;
        // Символы не совпадают — не палиндром
        if (str[start] != str[end]) return false;
        // Проверяем следующий уровень внутрь
        return isPalindrome(str, start + 1, end - 1);
    }

    int findSubstring(const std::string& text, const std::string& sub, size_t pos) {
        // Не хватает места для подстроки
        if (pos + sub.length() > text.length()) return -1;
        // Совпадение найдено
        if (text.substr(pos, sub.length()) == sub)
            return static_cast<int>(pos);
        // Проверяем следующую позицию
        return findSubstring(text, sub, pos + 1);
    }

    std::string reverseString(const std::string& str, size_t pos) {
        // Дошли до середины — возвращаем результат
        if (pos >= str.length() / 2) return str;
        // Копируем строку и меняем символы местами
        std::string temp = str;
        std::swap(temp[pos], temp[str.length() - 1 - pos]);
        // Рекурсивно обрабатываем следующую пару
        return reverseString(temp, pos + 1);
    }

} // namespace strutils