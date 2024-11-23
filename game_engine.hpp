#pragma once

#include "ship.hpp"
#include "enemy.hpp"
#include "board.hpp"
#include "bullet.hpp"
#include <vector>
#include <iostream>
#include <memory>  // Для умных указателей
#include <algorithm>  // Для STL алгоритмов

#ifdef _WIN32
#include <windows.h>  // Только для Windows
#endif

// Основной движок игры, объединяющий все элементы (корабль, враги, пули, игровое поле)
class GameEngine {
    std::unique_ptr<Ship> _ship;    // Умный указатель на корабль
    std::vector<Enemy> _enemies;   // Враги
    Bullet _bullet;                // Пуля
    Board _board;                  // Игровое поле
    bool _isGameOver;              // Флаг окончания игры

public:
    
    GameEngine();

    void Init();

    void Run();

private:
   
    void Draw();

    void Input();
    
    void Logic();
    
    void GameOver();
    // Обновление игрового состояния
    void Update();
    // Отображение игрового состояния
    void Render();
};
