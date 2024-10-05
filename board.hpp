#pragma once

// Класс для представления игрового поля
class Board {
    int _width;   // Ширина игрового поля
    int _height;  // Высота игрового поля
public:
    // Конструктор с параметрами (по умолчанию 20x20)
    Board(int width = 20, int height = 20);

    // Метод для получения ширины
    int GetWidth() const;

    // Метод для получения высоты
    int GetHeight() const;
};


  

  