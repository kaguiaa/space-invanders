#include "game_engine.hpp"

void GameEngine::Init()
{
    // Инициализация, если потребуется
}

void GameEngine::Input()
{
    if (GetAsyncKeyState(VK_UP))
    {
        if (!_bullet.IsActive())
        {
            _bullet = _ship.Shoot();
        }
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        _ship.MoveLeft();
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        _ship.MoveRight();
    }
    else if (GetAsyncKeyState(VK_ESCAPE))
    {
        _isGameOver = true;
    }
}