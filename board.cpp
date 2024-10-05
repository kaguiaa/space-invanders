#include "board.hpp"

// Конструктор
Board::Board(int width, int height) : _width(width), _height(height) {}

// Реализация метода для получения ширины
int Board::GetWidth() const {
    return _width;
}

// Реализация метода для получения высоты
int Board::GetHeight() const {
    return _height;
}

