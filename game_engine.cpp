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

GameEngine::GameEngine() : _board(20, 20), _isGameOver(false){


    // Создаем несколько врагов
    for (int i = 0; i < 5; i++)
    {
        _enemies.push_back(Enemy({i * 3 + 5, 0})); // Враги размещаются по горизонтали
    }
}

// Основной игровой цикл
void GameEngine::Run()
{
    while (!_isGameOver)
    {
        Draw();  // Отрисовка игрового поля
        Input(); // Ввод пользователя
        Logic(); // Обработка игровой логики
    }

    GameOver(); // Сообщение об окончании игры
}

// Метод для отрисовки игрового поля
void GameEngine::Draw()
{
    system("clear"); // Очистка экрана (Windows)

    // Отрисовка верхней границы
    for (int i = 0; i < _board.GetWidth() + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    // Отрисовка игрового поля
    for (int y = 0; y < _board.GetHeight(); y++)
    {
        for (int x = 0; x < _board.GetWidth(); x++)
        {
            bool isPrinted = false;
           
            // Отрисовка корабля
            if (_ship.GetPosition().x == x && _ship.GetPosition().y == y)
            {
                std::cout << "A"; // Символ корабля
                isPrinted = true;
            }

            // Отрисовка врагов
            for (const auto &enemy : _enemies)
            {
                if (enemy.GetPosition().x == x && enemy.GetPosition().y == y && enemy.IsAlive())
                {
                    std::cout << "E"; // Символ врага
                    isPrinted = true;
                    break;
                }
            }

            // Отрисовка пули
            if (_bullet.IsActive() && _bullet.GetPosition().x == x && _bullet.GetPosition().y == y)
            {
                std::cout << "*"; // Символ пули
                isPrinted = true;
            }

            if (!isPrinted)
                std::cout << " "; // Пустое место
        }
        std::cout << "#\n"; // Правая граница
    }

    // Отрисовка нижней границы
    for (int i = 0; i < _board.GetWidth() + 2; i++)
        std::cout << "#";
    std::cout << std::endl;
}

// Метод для обработки логики игры
void GameEngine::Logic()
{
    // Движение пули
    if (_bullet.IsActive())
    {
        _bullet.MoveUp(); // Пуля движется вверх
        if (_bullet.GetPosition().y < 0)
        {
            _bullet.Deactivate(); // Деактивируем пулю, если она ушла за границу
        }
    }

    // Проверка попадания пули во врагов
    for (auto &enemy : _enemies)
    {
        if (enemy.IsAlive() && _bullet.IsActive() && enemy.GetPosition().x == _bullet.GetPosition().x && enemy.GetPosition().y == _bullet.GetPosition().y)
        {
            enemy.Destroy();      // Уничтожаем врага
            _bullet.Deactivate(); // Деактивируем пулю
        }
    }

    // Движение врагов
    for (auto &enemy : _enemies)
    {
        if (enemy.IsAlive())
        {
            enemy.MoveDown(); // Враги движутся вниз
            if (enemy.GetPosition().y >= _board.GetHeight())
            {
                _isGameOver = true; // Игра заканчивается, если враги дошли до низа экрана
            }
        }
    }

    // Проверка на победу (все враги уничтожены)
    _isGameOver = std::all_of(_enemies.begin(), _enemies.end(), [](const Enemy &e)
                              { return !e.IsAlive(); });
}

// Метод для обработки окончания игры
void GameEngine::GameOver()
{
    std::cout << "Game Over!" << std::endl;
}