#pragma once

#include "point.hpp"

// Класс врага, управляющий его позицией и состоянием (жив/мертв)
class Enemy {
    Point _position;  // Текущая позиция врага
    bool _isAlive;    // Флаг, жив ли враг
public:
    Enemy(const Point& position) : _position(position), _isAlive(true) {}  // Конструктор врага с установкой позиции и состоянием "жив"

    // Возвращает текущую позицию врага
    Point GetPosition() const {
        return _position;
    }

    // Перемещает врага вниз
    void MoveDown() {
        _position.y++;
    }

    // Проверяет, жив ли враг
    bool IsAlive() const {
        return _isAlive;
    }

    // Уничтожает врага (меняет его состояние на "мертв")
    void Destroy() {
        _isAlive = false;
    }
};
