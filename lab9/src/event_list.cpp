#include "event_list.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>

namespace EventManager {

Event* createEvent(const char* date, const char* time,
                   const char* desc, const char* place) {
    Event* e = new Event;
    e->date = strdup(date);
    e->time = strdup(time);
    e->description = strdup(desc);
    e->place = strdup(place);
    e->next = nullptr;
    return e;
}

void destroyEvent(Event* e) {
    if (!e) return;
    free(e->date);
    free(e->time);
    free(e->description);
    free(e->place);
    delete e;
}

// Сравнение даты и времени: возвращает -1 если первое раньше, 0 равно, 1 позже
int compareDateTime(const char* d1, const char* t1,
                    const char* d2, const char* t2) {
    int cmp = strcmp(d1, d2);
    if (cmp != 0) return cmp < 0 ? -1 : 1;
    return strcmp(t1, t2) < 0 ? -1 : (strcmp(t1, t2) > 0 ? 1 : 0);
}

void addEvent(List& list, const char* date, const char* time,
              const char* desc, const char* place) {
    if (!date || !time || !desc || !place) return;

    Event* newEvent = createEvent(date, time, desc, place);

    // Вставка в хронологическом порядке
    if (!list.head || compareDateTime(date, time,
                                      list.head->date, list.head->time) < 0) {
        newEvent->next = list.head;
        list.head = newEvent;
        return;
    }

    Event* cur = list.head;
    while (cur->next &&
           compareDateTime(date, time, cur->next->date, cur->next->time) >= 0) {
        cur = cur->next;
    }
    newEvent->next = cur->next;
    cur->next = newEvent;
}

bool removeEventByDescription(List& list, const char* desc) {
    if (!list.head || !desc) return false;

    if (strcmp(list.head->description, desc) == 0) {
        Event* temp = list.head;
        list.head = list.head->next;
        destroyEvent(temp);
        return true;
    }

    Event* cur = list.head;
    while (cur->next && strcmp(cur->next->description, desc) != 0) {
        cur = cur->next;
    }
    if (!cur->next) return false;

    Event* temp = cur->next;
    cur->next = temp->next;
    destroyEvent(temp);
    return true;
}

Event* getNearestEvent(const List& list) {
    return list.head;  // список уже отсортирован
}

int countEventsInPlace(const List& list, const char* place) {
    if (!place) return 0;
    int cnt = 0;
    for (Event* cur = list.head; cur; cur = cur->next) {
        if (strcmp(cur->place, place) == 0) ++cnt;
    }
    return cnt;
}

void printAllToFile(const List& list, const char* filename) {
    std::ofstream out(filename);
    out << "Список событий (хронологический порядок):\n";
    for (Event* cur = list.head; cur; cur = cur->next) {
        out << "Дата: " << cur->date
            << ", Время: " << cur->time
            << ", Событие: " << cur->description
            << ", Место: " << cur->place << "\n";
    }

    if (list.head) {
        out << "Ближайшее событие: " << list.head->description
            << " (" << list.head->date << " " << list.head->time << ")\n";
    }

    int officeCount = countEventsInPlace(list, "Офис");
    out << "Событий в офисе: " << officeCount << "\n";
}

void clearList(List& list) {
    while (list.head) {
        Event* temp = list.head;
        list.head = list.head->next;
        destroyEvent(temp);
    }
}

}