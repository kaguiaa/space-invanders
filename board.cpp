#include "board.hpp"
#include <iostream>

// Конструктор
Board::Board(int width, int height) : _grid(height, std::vector<int>(width, 0)) {}

// Реализация метода для получения ширины
int Board::GetWidth() const {
    return _width;
}

// Реализация метода для получения высоты
int Board::GetHeight() const {
    return _height;
}

void Board::Draw() {
    for (auto& row : _grid) {
        for (auto& cell : row) {
            std::cout << (cell ? "X" : "O") << " ";
        }
        std::cout << std::endl;
    }
}
