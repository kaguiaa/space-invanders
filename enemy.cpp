#include "enemy.hpp"

// Определение методов класса Enemy

// Возвращает текущую позицию врага
Point Enemy::GetPosition() const {
    return _position;  // Возвращает позицию
}

// Перемещает врага вниз
void Enemy::MoveDown() {
    _position.y++;  // Увеличивает координату y позиции врага
}

// Проверяет, жив ли враг
bool Enemy::IsAlive() const {
    return _isAlive;  // Возвращает состояние врага
}

// Уничтожает врага (меняет его состояние на "мертв")
void Enemy::Destroy() {
    _isAlive = false;  // Устанавливает состояние врага как "мертв"
}
