#pragma once

#include "Board.h"
#include "Player.h"
#include "Button.h"

struct WinInfo
{
    bool win;
    int winCase; // 0 - horizontal, 1 - vertical, 2 - main diagonal, 3 - additional diagonal
    int index;   // index of cell for horizontal or vertical win, -1 for diagonal
};

struct GameState {
    Board board;
    Player playerX;
    Player playerO;
    Player* currentPlayer;
    int cellWidth;
    int cellHeight;
    bool isRunning;
    bool gameOver;
    WinInfo winInfo;
    Button playAgainButton;

    GameState(int winWidth, int winHeight)
        : board(),
          playerX('X'),
          playerO('0'),
          currentPlayer(&playerX),
          cellWidth(winWidth / 3),
          cellHeight(winHeight / 3),
          isRunning(true),
          gameOver(false),
          winInfo({false, -1, -1}),
          playAgainButton(winWidth / 2 - 75, winHeight / 2 - 25, 150, 50, {0, 0, 0, 128}, {255, 255, 255, 255})
    {
    }

    // resseting all the gameState
    void reset(int winWidth, int winHeight)
    {
        board = Board();
        currentPlayer = &playerX;
        cellWidth = winWidth / 3;
        cellHeight = winHeight / 3;
        gameOver = false;
        winInfo = {false, -1, -1};
    }
};