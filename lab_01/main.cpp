#include <iostream>
#include <string>
#include <clocale>

using namespace std;

class Car {
private:
    // Приватные поля
    string brand;
    string model;
    int year;
    double mileage;

public:
    // Конструктор по умолчанию
    Car() {
        brand = "Unknown";
        model = "Unknown";
        year = 2020;
        mileage = 0;
    }

    // Параметризованный конструктор с member initializer list
    Car(string br, string md, int yr, double mil)
        : brand(br), model(md), year(yr), mileage(mil) {
    }

    // Деструктор
    ~Car() {
        cout << "Объект удален" << endl;
    }

    // Геттеры
    string getBrand() { return brand; }
    string getModel() { return model; }
    int getYear() { return year; }
    double getMileage() { return mileage; }

    // Сеттеры
    void setBrand(string br) { brand = br; }
    void setModel(string md) { model = md; }
    void setYear(int yr) { year = yr; }
    void setMileage(double mil) { mileage = mil; }

    // Метод 1: Увеличение пробега
    void addMileage(double km) {
        mileage += km;
    }

    // Метод 2: Проверка техобслуживания (каждые 15000 км)
    bool needsMaintenance() {
        return mileage >= 15000;
    }

    // Метод 3: Возраст автомобиля
    int getAge() {
        return 2024 - year;
    }

    // Вывод информации
    void displayInfo() {
        cout << "Марка: " << brand << endl;
        cout << "Модель: " << model << endl;
        cout << "Год: " << year << endl;
        cout << "Пробег: " << mileage << " км" << endl;
        cout << "Возраст: " << getAge() << " лет" << endl;
        cout << "Требуется ТО: " << (needsMaintenance() ? "Да" : "Нет") << endl;
        cout << endl;
    }
};
    return 0;
}