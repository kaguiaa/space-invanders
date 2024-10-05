#include "bullet.hpp"
#include <iostream>

// Конструктор по умолчанию
Bullet::Bullet() : _isActive(false) {}

// Конструктор с позицией
Bullet::Bullet(const Point& position) : _position(position), _isActive(true) {}

// Перемещение пули вверх
void Bullet::MoveUp() {
    if (_isActive) {
        _position.y--;
    }
}

// Возвращение текущей позиции
Point Bullet::GetPosition() const {
    return _position;
}

// Проверка активности пули
bool Bullet::IsActive() const {
    return _isActive;
}

// Деактивация пули
void Bullet::Deactivate() {
    _isActive = false;
}

// Оператор сравнения
bool Bullet::operator==(const Bullet& other) const {
    return _position == other._position && _isActive == other._isActive;
}

// Оператор копирования
Bullet& Bullet::operator=(const Bullet& other) {
    if (this != &other) {
        _position = other._position;
        _isActive = other._isActive;
    }
    return *this;
}

// Оператор ввода
std::istream& operator>>(std::istream& in, Bullet& bullet) {
    in >> bullet._position >> bullet._isActive;
    return in;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& out, const Bullet& bullet) {
    out << "Bullet(Position: " << bullet._position << ", Active: " << (bullet._isActive ? "Yes" : "No") << ")";
    return out;
}
