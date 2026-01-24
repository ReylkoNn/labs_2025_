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
    car1.setMileage(20000);
    car1.displayInfo();

    // Использование методов
    cout << "Использование методов для car2:" << endl;
    car2.addMileage(500);
    cout << "Новый пробег car2: " << car2.getMileage() << " км" << endl;
    cout << "Нужно ТО: " << (car2.needsMaintenance() ? "Да" : "Нет") << endl;
    cout << "Возраст: " << car2.getAge() << " лет" << endl;
    cout << endl;

    // Работа с указателями (оператор ->)
    cout << "Работа с указателем (car3):" << endl;
    Car* car3 = new Car("Mercedes", "E-Class", 2018, 45000);
    car3->displayInfo();
    car3->addMileage(1000);
    cout << "Пробег после поездки: " << car3->getMileage() << " км" << endl;
    cout << endl;

    cout << "Удаление car3:" << endl;
    delete car3; // удаление объекта

    cout << endl << "=== Завершение программы ===" << endl;

    // Пауза перед завершением
    system("pause");

    return 0;
}