#include "event_list.h"
#include <fstream>
#include <iostream>

using namespace EventManager;

int main() {
    List eventList = { nullptr };

    std::ifstream in("input.txt");
    if (!in) {
        std::cerr << "Не удалось открыть input.txt\n";
        return 1;
    }

    int n;
    in >> n;
    in.ignore(); // пропустить перевод строки после числа

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(in, line);
        if (line.empty()) { --i; continue; }

        char date[12] = {}, time[6] = {}, desc[100] = {}, place[100] = {};
        if (sscanf(line.c_str(), "%11s %5s %99[^ ] %99[^\n]", date, time, desc, place) != 4) {
            continue; // некорректная строка
        }

        // Исправление описания (убираем подчёркивания → пробелы)
        for (char* p = desc; *p; ++p) if (*p == '_') *p = ' ';

        addEvent(eventList, date, time, desc, place);
    }

    printAllToFile(eventList, "output.txt");
    clearList(eventList);

    std::cout << "Готово! Результат записан в output.txt\n";
    return 0;
}