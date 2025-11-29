#ifndef LOG_ANALYZER_H
#define LOG_ANALYZER_H

#include <string>
#include <vector>

namespace LogAnalyzer {

    // Структура для хранения разобранной записи лога
    struct LogEntry {
        std::string timestamp;  // Временная метка
        std::string level;      // Уровень лога
        std::string message;    // Сообщение лога
    };

    // Функция для настройки консоли под UTF-8 (ДОБАВЬТЕ ЭТУ СТРОКУ)
    void setupConsole();

    // Функция 1: Извлечение данных из строки лога (C-строка)
    LogEntry parseLogEntry(const char* logLine);

    // Функция 2: Подсчет количества сообщений каждого уровня
    void countLogLevels(const std::vector<LogEntry>& logs,
        int& infoCount, int& warningCount, int& errorCount);

    // Функция 3: Поиск всех сообщений об ошибках (std::string)
    std::vector<std::string> findErrorMessages(const std::vector<LogEntry>& logs);

    // Функция 4: Извлечение IP-адресов из логов
    std::vector<std::string> extractIPAddresses(const std::vector<LogEntry>& logs);

    // Функция 5: Определение временного интервала логирования
    void getTimeInterval(const std::vector<LogEntry>& logs,
        std::string& startTime, std::string& endTime);

    // Вспомогательные функции
    std::vector<LogEntry> readLogsFromFile(const std::string& filename);
    void writeResultsToFile(const std::string& filename,
        const std::vector<LogEntry>& logs);
    std::string calculateDuration(const std::string& start, const std::string& end);
    bool isValidIP(const std::string& ip);
}

#endif