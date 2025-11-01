#include <iostream>
#include "rectangle.h"

int main() {
    using namespace Geometry;

    // Создание прямоугольников через динамическую память
    Rectangle* rect1 = createRectangle(5.0f, 3.0f);
    Rectangle* rect2 = createRectangle(5.0f, 3.0f);

    // Проверка успешности создания
    if (!rect1 || !rect2) {
        std::cout << "Failed to create rectangles\n";
        return 1;
    }

    // Вычисления для первого прямоугольника
    std::cout << "Rectangle 1:\n";
    std::cout << "Area: " << calculateArea(rect1) << "\n";
    std::cout << "Perimeter: " << calculatePerimeter(rect1) << "\n";

    // Масштабирование первого прямоугольника
    scaleRectangle(rect1, 2.0f);
    std::cout << "After scaling by 2:\n";
    std::cout << "Area: " << calculateArea(rect1) << "\n";
    std::cout << "Perimeter: " << calculatePerimeter(rect1) << "\n\n";

    // Вычисления для второго прямоугольника
    std::cout << "Rectangle 2:\n";
    std::cout << "Area: " << calculateArea(rect2) << "\n";
    std::cout << "Perimeter: " << calculatePerimeter(rect2) << "\n";

    // Освобождение памяти (без утечек)
    deleteRectangle(rect1);
    deleteRectangle(rect2);

    // Тестирование обработки ошибок
    Rectangle* badRect = createRectangle(-1.0f, 5.0f); // Неправильные размеры
    calculateArea(nullptr); // Нулевой указатель

    return 0;
}