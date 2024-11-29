#include "game_engine.hpp"
#include <algorithm> // Для алгоритмов STL
#include <windows.h>

GameEngine::GameEngine() : _board(20, 20), _ship(std::make_unique<Ship>(Point{10, 10})), _isGameOver(false) {
    for (int i = 0; i < 5; i++) {
        _enemies.push_back(Enemy({i * 3 + 5, 0})); // Враги размещаются по горизонтали
    }
}

void GameEngine::Init() {
    // Инициализация игры
}

void GameEngine::Input() {
    if (GetAsyncKeyState(VK_UP)) {
        if (!_bullet.IsActive()) {
            _bullet = _ship->Shoot();
        }
    } else if (GetAsyncKeyState(VK_LEFT)) {
        _ship->MoveLeft();
    } else if (GetAsyncKeyState(VK_RIGHT)) {
        _ship->MoveRight();
    } else if (GetAsyncKeyState(VK_ESCAPE)) {
        _isGameOver = true;
    }
}

void GameEngine::Update() {
    // Обновление состояния игры
    std::for_each(_enemies.begin(), _enemies.end(), [](Enemy &enemy) {
        enemy.MoveDown();
    });
}

void GameEngine::Render() {
    std::cout << "Rendering game..." << std::endl;
}

void GameEngine::Run() {
    while (!_isGameOver) {
        Draw();  // Отрисовка игрового поля
        Input(); // Ввод пользователя
        Logic(); // Обработка игровой логики
    }
    GameOver(); // Сообщение об окончании игры
}

void GameEngine::Draw() {
#ifdef _WIN32
    system("cls"); // Очистка экрана в Windows
#else
    system("clear"); // Очистка экрана в UNIX
#endif

    // Отрисовка верхней границы
    for (int i = 0; i < _board.GetWidth() + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for (int y = 0; y < _board.GetHeight(); y++) {
        for (int x = 0; x < _board.GetWidth(); x++) {
            bool isPrinted = false;

            if (_ship->GetPosition().x == x && _ship->GetPosition().y == y) {
                std::cout << "A"; // Символ корабля
                isPrinted = true;
            }

            for (const auto &enemy : _enemies) {
                if (enemy.GetPosition().x == x && enemy.GetPosition().y == y && enemy.IsAlive()) {
                    std::cout << "E"; // Символ врага
                    isPrinted = true;
                    break;
                }
            }

            if (_bullet.IsActive() && _bullet.GetPosition().x == x && _bullet.GetPosition().y == y) {
                std::cout << "*"; // Символ пули
                isPrinted = true;
            }

            if (!isPrinted)
                std::cout << " ";
        }
        std::cout << "#\n";
    }

    for (int i = 0; i < _board.GetWidth() + 2; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
}

void GameEngine::Logic() {
    if (_bullet.IsActive()) {
        _bullet.MoveUp();
        if (_bullet.GetPosition().y < 0) {
            _bullet.Deactivate();
        }
    }

    for (auto &enemy : _enemies) {
        if (enemy.IsAlive() && _bullet.IsActive() &&
            enemy.GetPosition().x == _bullet.GetPosition().x &&
            enemy.GetPosition().y == _bullet.GetPosition().y) {
            enemy.Destroy();
            _bullet.Deactivate();
        }
    }

    for (auto &enemy : _enemies) {
        if (enemy.IsAlive()) {
            enemy.MoveDown();
            if (enemy.GetPosition().y >= _board.GetHeight()) {
                _isGameOver = true;
            }
        }
    }

    if (std::all_of(_enemies.begin(), _enemies.end(), [](const Enemy &e) { return !e.IsAlive(); })) {
        _isGameOver = true;
    }
}

void GameEngine::GameOver() {
    std::cout << "Game Over!" << std::endl;
}
