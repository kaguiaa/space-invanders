#include "game_engine.hpp"

int main() {
    GameEngine engine;  // Создание объекта движка игры
    engine.Init();      // Инициализация игры
    engine.Run();       // Запуск игрового цикла
    return 0;
}
