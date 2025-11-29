#ifdef _WIN32
#pragma execution_character_set("utf-8")
#endif
#include <iostream>
#include <vector>
#include <fstream>
#include "log_analyzer.h"

using namespace LogAnalyzer;

int main() {
    // Настраиваем консоль для поддержки UTF-8
    setupConsole();

    std::cout << "=== Анализатор лог-файлов ===" << std::endl;
    std::cout << std::endl;

    try {
        // Чтение логов из файла
        std::cout << "Чтение логов из файла input.txt..." << std::endl;
        std::vector<LogEntry> logs = readLogsFromFile("input.txt");

        if (logs.empty()) {
            std::cerr << "Ошибка: Не удалось прочитать логи или файл пуст" << std::endl;
            return 1;
        }

        std::cout << "Успешно прочитано " << logs.size() << " записей логов" << std::endl;
        std::cout << std::endl;

        // Демонстрация работы функции 1 - парсинг C-строки
        std::cout << "Демонстрация парсинга C-строки:" << std::endl;
        const char* sampleLog = "2025-11-19 10:15:23 INFO Server started on 192.168.1.10";
        LogEntry parsedEntry = parseLogEntry(sampleLog);
        std::cout << "Результат парсинга - Время: " << parsedEntry.timestamp
            << ", Уровень: " << parsedEntry.level
            << ", Сообщение: " << parsedEntry.message << std::endl;
        std::cout << std::endl;

        // Демонстрация работы функции 2 - подсчет уровней
        int infoCount, warningCount, errorCount;
        countLogLevels(logs, infoCount, warningCount, errorCount);
        std::cout << "Статистика по уровням логирования:" << std::endl;
        std::cout << "INFO: " << infoCount << " записей" << std::endl;
        std::cout << "WARNING: " << warningCount << " записей" << std::endl;
        std::cout << "ERROR: " << errorCount << " записей" << std::endl;
        std::cout << std::endl;

        // Демонстрация работы функции 3 - поиск ошибок
        std::vector<std::string> errorMessages = findErrorMessages(logs);
        std::cout << "Найдено " << errorMessages.size() << " сообщений об ошибках" << std::endl;
        std::cout << std::endl;

        // Демонстрация работы функции 4 - извлечение IP-адресов
        std::vector<std::string> ipAddresses = extractIPAddresses(logs);
        std::cout << "Найдено " << ipAddresses.size() << " уникальных IP-адресов:" << std::endl;
        for (const auto& ip : ipAddresses) {
            std::cout << "  - " << ip << std::endl;
        }
        std::cout << std::endl;

        // Демонстрация работы функции 5 - временной интервал
        std::string startTime, endTime;
        getTimeInterval(logs, startTime, endTime);
        std::cout << "Временной интервал логирования:" << std::endl;
        std::cout << "Начало: " << startTime << std::endl;
        std::cout << "Конец: " << endTime << std::endl;
        std::cout << std::endl;

        // Запись результатов в файл
        std::cout << "Запись полного отчета в файл output.txt..." << std::endl;
        writeResultsToFile("output.txt", logs);

        std::cout << std::endl;
        std::cout << "Программа завершена успешно!" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}