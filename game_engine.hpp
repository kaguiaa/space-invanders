#pragma once

#include "ship.hpp"
#include "enemy.hpp"
#include "board.hpp"
#include "bullet.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>

// Основной движок игры, объединяющий все элементы (корабль, враги, пули, игровое поле)
class GameEngine {
    Ship _ship;                // Корабль игрока
    std::vector<Enemy> _enemies; // Враги
    Bullet _bullet;            // Пуля
    Board _board;              // Игровое поле
    bool _isGameOver;          // Флаг окончания игры

public:
    // Конструктор движка, инициализирующий врагов и игровое поле
    GameEngine();
    // Метод инициализации (можно добавить дополнительные настройки)
    void Init();
    // Основной игровой цикл
    void Run();

private:
    // Метод для отрисовки игрового поля
    void Draw();
    void Input();
    // Метод для обработки логики игры
    void Logic();
    // Метод для обработки окончания игры
    void GameOver();
};
