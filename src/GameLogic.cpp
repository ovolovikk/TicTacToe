#include "GameLogic.h"
#include <iostream>

bool GameLogic::processMove(GameState &gameState, int row, int col)
{
    if(gameState.board.setCell(row, col, gameState.currentPlayer->getSymbol()))
    {
        int winCase, winIdx;
        if(gameState.board.hasSomeoneWin(gameState.currentPlayer, winCase, winIdx))
        {
            std::cout << "Player " << gameState.currentPlayer->getSymbol() << " wins!\n";
            gameState.winInfo.win = true;
            gameState.winInfo.winCase = winCase;
            gameState.winInfo.index = winIdx;
            gameState.gameOver = true;
            return true;
        }

        // Check for draw if board is full
        if(gameState.board.isFull())
        {
            std::cout << "A Draw!\n";
            gameState.winInfo.win = false;
            gameState.gameOver = true;
            return true;
        }
        // switch to the other player only if game is not over
        gameState.currentPlayer = (gameState.currentPlayer->getSymbol() == 'X') 
                                 ? &gameState.playerO 
                                 : &gameState.playerX;                     
    }
    return false;
}