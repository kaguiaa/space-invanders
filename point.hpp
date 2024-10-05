#pragma once
#include <iostream>

// Структура для представления координат точки
struct Point {
    int x; // X-координата
    int y; // Y-координата

    // Оператор сравнения для Point
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y; // Сравнение координат
    }

    // Операторы ввода и вывода
    friend std::istream& operator>>(std::istream& in, Point& point);
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

