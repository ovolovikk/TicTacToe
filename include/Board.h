#pragma once

#include <SDL2/SDL.h>

class Board {
private:
    char cells[3][3];
public:
    Board();
    bool setCell(int row, int col, char symbol);
    char getCell(int row, int col) const;
};
