#include "rectangle.h"
#include <iostream>

namespace Geometry {
    Rectangle* createRectangle(float w, float h) {
        // Проверка корректности входных данных
        if (w <= 0 || h <= 0) {
            std::cout << "Error: dimensions must be positive\n";
            return nullptr;
        }

        Rectangle* rect = new Rectangle;
        rect->width = w;
        rect->height = h;
        return rect;
    }

    void deleteRectangle(Rectangle* rect) {
        // Освобождение памяти
        delete rect;
    }

    float calculateArea(const Rectangle* rect) {
        // Проверка на нулевой указатель
        if (!rect) {
            std::cout << "Error: null pointer passed\n";
            return 0;
        }
        return rect->width * rect->height;
    }

    float calculatePerimeter(const Rectangle* rect) {
        // Проверка на нулевой указатель
        if (!rect) {
            std::cout << "Error: null pointer passed\n";
            return 0;
        }
        return 2 * (rect->width + rect->height);
    }

    void scaleRectangle(Rectangle* rect, float factor) {
        // Проверка указателя и коэффициента
        if (!rect) {
            std::cout << "Error: null pointer passed\n";
            return;
        }
        if (factor <= 0) {
            std::cout << "Error: scale factor must be positive\n";
            return;
        }

        // Масштабирование размеров
        rect->width *= factor;
        rect->height *= factor;
    }
}