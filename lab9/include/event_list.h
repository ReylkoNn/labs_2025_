#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include <string>

namespace EventManager {

    struct Event {
        char* date;
        char* time;
        char* description;
        char* place;
        Event* next;
    };

    struct List {
        Event* head;
    };

    // Функции
    void addEvent(List& list, const char* date, const char* time,
                  const char* desc, const char* place);

    bool removeEventByDescription(List& list, const char* desc);

    Event* getNearestEvent(const List& list);

    int countEventsInPlace(const List& list, const char* place);

    void printAllToFile(const List& list, const char* filename);

    void clearList(List& list);

    // Вспомогательные
    Event* createEvent(const char* date, const char* time,
                       const char* desc, const char* place);
    void destroyEvent(Event* e);
    int compareDateTime(const char* d1, const char* t1,
                        const char* d2, const char* t2);

} // namespace EventManager

#endif // EVENT_LIST_H