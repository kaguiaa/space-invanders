#pragma once

// Класс для представления игрового поля
class Board {
    int _width;   // Ширина игрового поля
    int _height;  // Высота игрового поля
public:
    // Конструктор поля с указанием ширины и высоты
    Board(int width = 20, int height = 20) : _width(width), _height(height) {}

    // Возвращает ширину игрового поля
    int GetWidth() const {
        return _width;
    }

    // Возвращает высоту игрового поля
    int GetHeight() const {
        return _height;
    }
};
