#pragma once

#include "point.hpp"

// Класс пули, который хранит ее позицию и активность
class Bullet {
    Point _position;  // Текущая позиция пули
    bool _isActive;   // Флаг, активна ли пуля
public:
    Bullet() : _isActive(false) {}  // Конструктор по умолчанию, пуля неактивна
    Bullet(const Point& position) : _position(position), _isActive(true) {}  // Конструктор с установкой позиции и активацией пули

    // Метод для перемещения пули вверх
    void MoveUp() {
        if (_isActive) {
            _position.y--;
        }
    }

    // Возвращает текущую позицию пули
    Point GetPosition() const {
        return _position;
    }

    // Проверяет, активна ли пуля
    bool IsActive() const {
        return _isActive;
    }

    // Деактивирует пулю
    void Deactivate() {
        _isActive = false;
    }
};
