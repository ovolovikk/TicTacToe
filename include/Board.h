#pragma once

#include "Player.h"
#include <SDL2/SDL.h>


class Board {
private:
    char cells[3][3]; // could be only empty or 'X', '0'
public:
    Board();

    // setCell() places the symbol into a specific cell.
    bool setCell(int row, int col, char symbol);

    char getCell(int row, int col) const;

    // hasSomeoneWin() checks if the given player has a win condition.
    // winCase: 0 - horizontal, 1 - vertical, 2 - main diagonal, 3 - additional diagonal.
    // index: row index for horizontal, column index for vertical wins; -1 for diagonals.
    bool hasSomeoneWin(Player* player, int &winCase, int &index);

    bool isFull() const;
};
