#pragma once
#include "point.hpp"

class Bullet {
    Point _position;
    bool _isActive;
public:
    Bullet();
    Bullet(const Point& position);
    void MoveUp();
    Point GetPosition() const;
    bool IsActive() const;
    void Deactivate();
    
    // Операторы сравнения, копирования, ввода/вывода
    bool operator==(const Bullet& other) const;
    Bullet& operator=(const Bullet& other);
    friend std::istream& operator>>(std::istream& in, Bullet& bullet);
    friend std::ostream& operator<<(std::ostream& out, const Bullet& bullet);
};

