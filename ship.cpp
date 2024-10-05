#include "ship.hpp"

// Перемещает корабль влево
void Ship::MoveLeft() {
    if (_position.x > 0) _position.x--;  // Уменьшает координату x, если это возможно
}

// Перемещает корабль вправо
void Ship::MoveRight() {
    if (_position.x < 19) _position.x++;  // Увеличивает координату x, если это возможно
}

// Стреляет с позиции корабля и возвращает снаряд
Bullet Ship::Shoot() const {
    return Bullet({ _position.x, _position.y - 1 });  // Создает снаряд на позиции выше корабля
}