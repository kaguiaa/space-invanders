#pragma once

#include "ship.hpp"
#include "enemy.hpp"
#include "board.hpp"
#include "bullet.hpp"
#include <vector>
#include <iostream>
#include <conio.h>  // Для захвата клавиш в Windows

// Основной движок игры, объединяющий все элементы (корабль, враги, пули, игровое поле)
class GameEngine {
    Ship _ship;                // Корабль игрока
    std::vector<Enemy> _enemies; // Враги
    Bullet _bullet;            // Пуля
    Board _board;              // Игровое поле
    bool _isGameOver;          // Флаг окончания игры

public:
    // Конструктор движка, инициализирующий врагов и игровое поле
    GameEngine() : _board(20, 20), _isGameOver(false) {
        // Создаем несколько врагов
        for (int i = 0; i < 5; i++) {
            _enemies.push_back(Enemy({ i * 3 + 5, 0 }));  // Враги размещаются по горизонтали
        }
    }

    // Метод инициализации (можно добавить дополнительные настройки)
    void Init() {
        // Инициализация, если потребуется
    }

    // Основной игровой цикл
    void Run() {
        while (!_isGameOver) {
            Draw();  // Отрисовка игрового поля
            Input();  // Ввод пользователя
            Logic();  // Обработка игровой логики
        }

        GameOver();  // Сообщение об окончании игры
    }

private:
    // Метод для отрисовки игрового поля
    void Draw() {
        system("cls");  // Очистка экрана (Windows)

        // Отрисовка верхней границы
        for (int i = 0; i < _board.GetWidth() + 2; i++) std::cout << "#";
        std::cout << std::endl;

        // Отрисовка игрового поля
        for (int y = 0; y < _board.GetHeight(); y++) {
            for (int x = 0; x < _board.GetWidth(); x++) {
                bool isPrinted = false;

                // Отрисовка корабля
                if (_ship.GetPosition().x == x && _ship.GetPosition().y == y) {
                    std::cout << "A";  // Символ корабля
                    isPrinted = true;
                }

                // Отрисовка врагов
                for (const auto& enemy : _enemies) {
                    if (enemy.GetPosition().x == x && enemy.GetPosition().y == y && enemy.IsAlive()) {
                        std::cout << "E";  // Символ врага
                        isPrinted = true;
                        break;
                    }
                }

                // Отрисовка пули
                if (_bullet.IsActive() && _bullet.GetPosition().x == x && _bullet.GetPosition().y == y) {
                    std::cout << "*";  // Символ пули
                    isPrinted = true;
                }

                if (!isPrinted) std::cout << " ";  // Пустое место
            }
            std::cout << "#\n";  // Правая граница
        }

        // Отрисовка нижней границы
        for (int i = 0; i < _board.GetWidth() + 2; i++) std::cout << "#";
        std::cout << std::endl;
    }

    // Метод для обработки ввода с клавиатуры
    void Input() {
        if (_kbhit()) {  // Проверка на нажатие клавиши
            switch (_getch()) {
                case 'a':  // Движение влево
                    _ship.MoveLeft();
                    break;
                case 'd':  // Движение вправо
                    _ship.MoveRight();
                    break;
                case 'w':  // Выстрел
                    if (!_bullet.IsActive()) {
                        _bullet = _ship.Shoot();
                    }
                    break;
                case 'x':  // Выход из игры
                    _isGameOver = true;
                    break;
            }
        }
    }

    // Метод для обработки логики игры
    void Logic() {
        // Движение пули
        if (_bullet.IsActive()) {
            _bullet.MoveUp();  // Пуля движется вверх
            if (_bullet.GetPosition().y < 0) {
                _bullet.Deactivate();  // Деактивируем пулю, если она ушла за границу
            }
        }

        // Проверка попадания пули во врагов
        for (auto& enemy : _enemies) {
            if (enemy.IsAlive() && _bullet.IsActive() && enemy.GetPosition().x == _bullet.GetPosition().x && enemy.GetPosition().y == _bullet.GetPosition().y) {
                enemy.Destroy();  // Уничтожаем врага
                _bullet.Deactivate();  // Деактивируем пулю
            }
        }

        // Движение врагов
        for (auto& enemy : _enemies) {
            if (enemy.IsAlive()) {
                enemy.MoveDown();  // Враги движутся вниз
                if (enemy.GetPosition().y >= _board.GetHeight()) {
                    _isGameOver = true;  // Игра заканчивается, если враги дошли до низа экрана
                }
            }
        }

        // Проверка на победу (все враги уничтожены)
        _isGameOver = std::all_of(_enemies.begin(), _enemies.end(), [](const Enemy& e) { return !e.IsAlive(); });
    }

    // Метод для обработки окончания игры
    void GameOver() {
        std::cout << "Game Over!" << std::endl;
    }
};
