#pragma once
#include "point.hpp"
#include "bullet.hpp"

// Класс для корабля
class Ship {
    Point _position;  // Позиция корабля
public:
    Ship()  = default;
    // Конструктор
    Ship(const Point& position);

    // Двигает корабль влево
    void MoveLeft();

    // Двигает корабль вправо
    void MoveRight();

    // Стреляет с позиции корабля
    Bullet Shoot() const;

    Point GetPosition() const;
};
