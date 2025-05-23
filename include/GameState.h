#pragma once

#include "Board.h"
#include "Player.h"

struct GameState {
    Board board;
    Player playerX;
    Player playerO;
    Player* currentPlayer;
    int cellWidth;
    int cellHeight;
    bool isRunning;

    GameState(int winWidth, int winHeight)
        : board(),
          playerX('X'),
          playerO('0'),
          currentPlayer(&playerX),
          cellWidth(winWidth / 3),
          cellHeight(winHeight / 3),
          isRunning(true)
    {
    }
};