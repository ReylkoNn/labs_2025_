#include "AnagramDictionary.h"
#include <algorithm>
#include <iostream>
#include <cctype>

// Вычисление сигнатуры слова: все буквы в нижний регистр и сортировка
// Добавлен const в конец
std::string anagram::AnagramDictionary::getSignature(const std::string& word) const {
    std::string sig = word;
    // Приводим к нижнему регистру
    for (char& c : sig) {
        c = std::tolower(c);
    }
    // Сортируем символы
    std::sort(sig.begin(), sig.end());
    return sig;
}

// Добавление слова в словарь с проверкой корректности
void anagram::AnagramDictionary::addWord(const std::string& word) {
    // Проверка на пустую строку
    if (word.empty()) {
        std::cout << "Error: empty word ignored.\n";
        return;
    }
    // Проверка, что слово состоит только из букв
    for (char c : word) {
        if (!std::isalpha(c)) {
            std::cout << "Error: word \"" << word << "\" contains non-letter characters. Ignored.\n";
            return;
        }
    }

    // Добавляем слово в группу по его сигнатуре
    // Теперь getSignature можно вызывать без проблем
    std::string sig = getSignature(word);
    groups[sig].push_back(word);
}

// Поиск анаграмм для заданного слова
std::vector<std::string> anagram::AnagramDictionary::findAnagrams(const std::string& word) const {
    std::vector<std::string> result;
    std::string sig = getSignature(word);  // Теперь работает в const-методе

    // Ищем группу по сигнатуре
    auto it = groups.find(sig);
    if (it != groups.end()) {
        // Добавляем все слова из группы, кроме самого запроса
        for (const std::string& w : it->second) {
            if (w != word) {
                result.push_back(w);
            }
        }
    }
    return result;
}

// Перестройка групп — в этой реализации всё происходит автоматически
void anagram::AnagramDictionary::buildGroups() {
    // Группировка выполняется при добавлении слов, поэтому здесь ничего не делаем
}

// Вывод всех групп анаграмм (только те, где больше одного слова)
void anagram::AnagramDictionary::printAllGroups() const {
    if (groups.empty()) {
        std::cout << "Dictionary is empty.\n";
        return;
    }

    int groupNumber = 1;
    bool hasAnyGroup = false;  // Флаг: была ли выведена хоть одна группа с анаграммами

    for (const auto& pair : groups) {
        // Пропускаем группы с одним словом
        if (pair.second.size() < 2) continue;

        // Выводим группу
        std::cout << "Group " << groupNumber << " (key: " << pair.first << "):\n";
        for (const std::string& word : pair.second) {
            std::cout << "- " << word << "\n";
        }
        ++groupNumber;
        hasAnyGroup = true;
    }

    // Если не было групп с анаграммами
    if (!hasAnyGroup) {
        std::cout << "No anagram groups found (all words are unique).\n";
    }
}