#ifndef ANAGRAM_DICTIONARY_H
#define ANAGRAM_DICTIONARY_H
// Include guards для защиты от повторного включения

#include <map>
#include <vector>
#include <string>

namespace anagram {
    // Пространство имён для избежания конфликтов имён

    class AnagramDictionary {
    private:
        // Ключ — отсортированная строка в нижнем регистре (сигнатура анаграммы)
        // Значение — вектор всех оригинальных слов с этой сигнатурой
        std::map<std::string, std::vector<std::string>> groups;

        // Вспомогательная функция: вычисляет сигнатуру слова
        // Добавлен const — теперь можно вызывать из const-методов
        std::string getSignature(const std::string& word) const;

    public:
        // Конструктор по умолчанию
        AnagramDictionary() = default;

        // 1. Добавляет слово в словарь
        void addWord(const std::string& word);

        // 2. Находит все анаграммы заданного слова (исключая само слово)
        std::vector<std::string> findAnagrams(const std::string& word) const;

        // 3. Перестраивает группы анаграмм (в данной реализации не требуется)
        void buildGroups();

        // 4. Выводит все группы анаграмм (только с 2+ словами)
        void printAllGroups() const;
    };

} // namespace anagram

#endif // ANAGRAM_DICTIONARY_H