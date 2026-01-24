#include <iostream>
#include <string>
#include <clocale>
#include <ctime>

using namespace std;

class Car {
private:
    // Приватные поля
    string brand;
    string model;
    int year;
    double kilometrage; // километраж (не mileage - мили)

public:
    // Конструктор по умолчанию
    Car() {
        brand = "Unknown";
        model = "Unknown";
        year = 2020;
        kilometrage = 0;
    }

    // Параметризованный конструктор с member initializer list
    Car(string br, string md, int yr, double km)
        : brand(br), model(md), year(yr), kilometrage(km) {
    }

    // Деструктор
    ~Car() {
        cout << "Объект удален" << endl;
    }

    // Геттеры
    string getBrand() { return brand; }
    string getModel() { return model; }
    int getYear() { return year; }
    double getKilometrage() { return kilometrage; }

    // Сеттеры
    void setBrand(string br) { brand = br; }
    void setModel(string md) { model = md; }
    void setYear(int yr) { year = yr; }
    void setKilometrage(double km) { kilometrage = km; }

    // Метод 1: Увеличение пробега
    void addKilometrage(double km) {
        kilometrage += km;
    }

    // Метод 2: Проверка техобслуживания (каждые 15000 км)
    bool needsMaintenance() {
        return kilometrage >= 15000;
    }

    // Метод 3: Возраст автомобиля (получение текущего года из системы)
    int getAge() {
        // Получаем текущий год из системы
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;

        return currentYear - year;
    }

    // Вывод информации
    void displayInfo() {
        cout << "Марка: " << brand << endl;
        cout << "Модель: " << model << endl;
        cout << "Год: " << year << endl;
        cout << "Пробег: " << kilometrage << " км" << endl;
        cout << "Возраст: " << getAge() << " лет" << endl;
        cout << "Требуется ТО: " << (needsMaintenance() ? "Да" : "Нет") << endl;
        cout << endl;
    }
};

int main() {
    // Настройка кодировки для русского языка
    setlocale(LC_ALL, "Russian");

    cout << "=== Программа запущена ===" << endl << endl;

    // Создание объекта по умолчанию
    cout << "Объект 1 (по умолчанию):" << endl;
    Car car1;
    car1.displayInfo();

    // Создание объекта с параметрами
    cout << "Объект 2 (с параметрами):" << endl;
    Car car2("Toyota", "Camry", 2020, 30000);
    car2.displayInfo();

    // Использование сеттеров
    cout << "Изменение объекта 1 через сеттеры:" << endl;
    car1.setBrand("BMW");
    car1.setModel("X5");
    car1.setYear(2019);
    car1.setKilometrage(20000);
    car1.displayInfo();

    // Использование методов
    cout << "Использование методов для car2:" << endl;
    car2.addKilometrage(500);
    cout << "Новый пробег car2: " << car2.getKilometrage() << " км" << endl;
    cout << "Нужно ТО: " << (car2.needsMaintenance() ? "Да" : "Нет") << endl;
    cout << "Возраст: " << car2.getAge() << " лет" << endl;
    cout << endl;

    // Работа с указателями (оператор ->)
    cout << "Работа с указателем (car3):" << endl;
    Car* car3 = new Car("Mercedes", "E-Class", 2018, 45000);
    car3->displayInfo();
    car3->addKilometrage(1000);
    cout << "Пробег после поездки: " << car3->getKilometrage() << " км" << endl;
    cout << endl;

    cout << "Удаление car3:" << endl;
    delete car3;

    cout << endl << "=== Завершение программы ===" << endl;

    system("pause");

    return 0;
}