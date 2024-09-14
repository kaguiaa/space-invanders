#pragma once

#include "point.hpp"
#include "bullet.hpp"

// Класс корабля игрока, управляющий его движением и стрельбой
class Ship {
    Point _position;  // Текущая позиция корабля
public:
    // Конструктор корабля с установкой позиции по умолчанию
    Ship() : _position({10, 20}) {}

    // Возвращает текущую позицию корабля
    Point GetPosition() const {
        return _position;
    }

    // Двигает корабль влево
    void MoveLeft() {
        if (_position.x > 0) _position.x--;
    }

    // Двигает корабль вправо
    void MoveRight() {
        if (_position.x < 19) _position.x++;
    }

    // Стреляет пулей, создавая новую пулю перед кораблем
    Bullet Shoot() const {
        return Bullet({ _position.x, _position.y - 1 });
    }
};
