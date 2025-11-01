#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace Geometry {
    struct Rectangle {
        float width;
        float height;
    };

    // Создать прямоугольник
    Rectangle* createRectangle(float w, float h);

    // Удалить прямоугольник
    void deleteRectangle(Rectangle* rect);

    // Вычислить площадь
    float calculateArea(const Rectangle* rect);

    // Вычислить периметр
    float calculatePerimeter(const Rectangle* rect);

    // Масштабировать прямоугольник
    void scaleRectangle(Rectangle* rect, float factor);
}

#endif