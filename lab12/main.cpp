#include <iostream>
#include <string>
#include "AnagramDictionary.h"

int main() {
    std::cout << "=== Anagram Finder ===\n";

    int count;
    std::cout << "Enter the number of words: ";
    std::cin >> count;

    // Проверка корректности количества слов
    if (count <= 0) {
        std::cout << "Error: number must be positive.\n";
        return 1;
    }

    // Очистка буфера после чтения числа
    std::cin.ignore();

    anagram::AnagramDictionary dict;

    std::cout << "Enter words:\n";
    for (int i = 0; i < count; ++i) {
        std::string word;
        std::cout << "> ";
        std::getline(std::cin, word);

        // Удаление ведущих и конечных пробелов
        size_t start = word.find_first_not_of(" \t");
        if (start != std::string::npos) {
            size_t end = word.find_last_not_of(" \t");
            word = word.substr(start, end - start + 1);
        }
        else {
            word.clear();
        }

        dict.addWord(word);
    }

    // Вывод всех найденных групп анаграмм
    std::cout << "\nAnagram groups:\n";
    dict.printAllGroups();

    // Интерактивный поиск анаграмм
    std::string query;
    while (true) {
        std::cout << "\nEnter a word to find anagrams (or 'exit' to quit): ";
        std::getline(std::cin, query);

        // Удаление пробелов по краям
        size_t start = query.find_first_not_of(" \t");
        if (start != std::string::npos) {
            size_t end = query.find_last_not_of(" \t");
            query = query.substr(start, end - start + 1);
        }
        else {
            query.clear();
        }

        if (query == "exit") {
            break;
        }

        if (query.empty()) {
            std::cout << "Empty input. Try again.\n";
            continue;
        }

        std::vector<std::string> anagrams = dict.findAnagrams(query);

        std::cout << "Anagrams of \"" << query << "\": ";
        if (anagrams.empty()) {
            std::cout << "none\n";
        }
        else {
            for (size_t i = 0; i < anagrams.size(); ++i) {
                std::cout << anagrams[i];
                if (i < anagrams.size() - 1) std::cout << ", ";
            }
            std::cout << "\n";
        }
    }

    std::cout << "Program finished.\n";
    return 0;
}