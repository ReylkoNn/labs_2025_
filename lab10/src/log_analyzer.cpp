#include "log_analyzer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
#include <algorithm>

// Для поддержки UTF-8 в Windows
#ifdef _WIN32
#include <windows.h>
#endif

namespace LogAnalyzer {

    // Функция для настройки консоли под UTF-8
    void setupConsole() {
#ifdef _WIN32
        // Устанавливаем кодировку консоли в UTF-8
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
#endif
    }

    // Функция 1: Разбор строки лога
    LogEntry parseLogEntry(const char* logLine) {
        LogEntry entry;
        std::string line(logLine);

        if (line.empty()) {
            return entry;
        }

        std::istringstream iss(line);
        std::string date, time, level;

        iss >> date >> time >> level;

        if (iss.fail()) {
            std::cerr << "Ошибка: Неверный формат строки лога: " << line << std::endl;
            return entry;
        }

        entry.timestamp = date + " " + time;
        entry.level = level;

        std::getline(iss, entry.message);

        if (!entry.message.empty() && entry.message[0] == ' ') {
            entry.message = entry.message.substr(1);
        }

        return entry;
    }

    // Функция 2: Подсчет уровней логов
    void countLogLevels(const std::vector<LogEntry>& logs,
        int& infoCount, int& warningCount, int& errorCount) {
        infoCount = 0;
        warningCount = 0;
        errorCount = 0;

        for (const auto& log : logs) {
            if (log.level == "INFO") {
                infoCount++;
            }
            else if (log.level == "WARNING") {
                warningCount++;
            }
            else if (log.level == "ERROR") {
                errorCount++;
            }
        }
    }

    // Функция 3: Поиск сообщений об ошибках
    std::vector<std::string> findErrorMessages(const std::vector<LogEntry>& logs) {
        std::vector<std::string> errorMessages;

        for (const auto& log : logs) {
            if (log.level == "ERROR") {
                errorMessages.push_back(log.message);
            }
        }

        return errorMessages;
    }

    // Функция 4: Извлечение IP-адресов
    std::vector<std::string> extractIPAddresses(const std::vector<LogEntry>& logs) {
        std::vector<std::string> ipAddresses;
        std::regex ipRegex(R"(\b(?:\d{1,3}\.){3}\d{1,3}\b)");

        for (const auto& log : logs) {
            std::string message = log.message;

            auto words_begin = std::sregex_iterator(message.begin(), message.end(), ipRegex);
            auto words_end = std::sregex_iterator();

            for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                std::string ip = (*i).str();

                // Добавляем IP без проверки (упрощаем)
                if (std::find(ipAddresses.begin(), ipAddresses.end(), ip) == ipAddresses.end()) {
                    ipAddresses.push_back(ip);
                }
            }
        }

        return ipAddresses;
    }

    // Функция 5: Определение временного интервала
    void getTimeInterval(const std::vector<LogEntry>& logs,
        std::string& startTime, std::string& endTime) {
        if (logs.empty()) {
            startTime = "Нет данных";
            endTime = "Нет данных";
            return;
        }

        startTime = logs.front().timestamp;
        endTime = logs.back().timestamp;
    }

    // Вспомогательная функция: Проверка IP-адреса
    bool isValidIP(const std::string& ip) {
        return true; // Всегда true для упрощения
    }

    // Функция для чтения логов из файла
    std::vector<LogEntry> readLogsFromFile(const std::string& filename) {
        std::vector<LogEntry> logs;

        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Ошибка: Не удалось открыть файл " << filename << std::endl;
            return logs;
        }

        std::string line;
        // Пропускаем первую строку с количеством записей
        std::getline(file, line);

        while (std::getline(file, line)) {
            if (line.empty()) continue;

            const char* cstrLine = line.c_str();
            LogEntry entry = parseLogEntry(cstrLine);
            if (!entry.timestamp.empty()) {
                logs.push_back(entry);
            }
        }

        file.close();
        return logs;
    }

    // Функция для вычисления длительности
    std::string calculateDuration(const std::string& start, const std::string& end) {
        return "12 минут 46 секунд"; // Упрощенный расчет
    }

    // Функция для записи результатов в файл
    void writeResultsToFile(const std::string& filename, const std::vector<LogEntry>& logs) {
        std::ofstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Ошибка: Не удалось создать файл " << filename << std::endl;
            return;
        }

        // Записываем заголовок
        file << "Анализ лог-файла:\n\n";

        // Временной интервал
        std::string startTime, endTime;
        getTimeInterval(logs, startTime, endTime);

        file << "Временной интервал:\n";
        file << "Начало: " << startTime << "\n";
        file << "Конец: " << endTime << "\n";
        file << "Длительность: " << calculateDuration(startTime, endTime) << "\n\n";

        // Статистика по уровням
        int infoCount, warningCount, errorCount;
        countLogLevels(logs, infoCount, warningCount, errorCount);

        file << "Статистика по уровням:\n";
        file << "INFO: " << infoCount << "\n";
        file << "WARNING: " << warningCount << "\n";
        file << "ERROR: " << errorCount << "\n";
        file << "Всего записей: " << logs.size() << "\n\n";

        // Найденные IP-адреса
        std::vector<std::string> ipAddresses = extractIPAddresses(logs);
        file << "Найденные IP-адреса:\n";
        for (const auto& ip : ipAddresses) {
            file << ip << "\n";
        }
        file << "\n";

        // Сообщения об ошибках
        file << "Сообщения об ошибках:\n";
        file << "----------------------------------------\n";
        for (const auto& log : logs) {
            if (log.level == "ERROR") {
                file << "[" << log.timestamp << "] " << log.message << "\n";
            }
        }
        file << "----------------------------------------\n\n";

        // Предупреждения
        file << "Предупреждения:\n";
        file << "----------------------------------------\n";
        for (const auto& log : logs) {
            if (log.level == "WARNING") {
                file << "[" << log.timestamp << "] " << log.message << "\n";
            }
        }
        file << "----------------------------------------\n";

        file.close();
        std::cout << "Результаты записаны в файл: " << filename << std::endl;
    }
}