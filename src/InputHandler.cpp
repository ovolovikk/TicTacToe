#include "InputHandler.h"
#include <iostream>

void InputHandler::processEvent(const SDL_Event &event, GameState &gameState, bool &isRunning)
{

    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(gameState.gameOver)
        {
            if(gameState.playAgainButton.handleEvent(event))
            {
                int winW = gameState.cellWidth * 3;
                int winH = gameState.cellHeight * 3;
                gameState.reset(winW, winH);
            }
            return;
        }
        int mouseX = event.button.x;
        int mouseY = event.button.y;
        int col = mouseX / gameState.cellWidth;
        int row = mouseY / gameState.cellHeight;
        if(row >= 0 && row < 3 && col >= 0 && col < 3)
        {
            if(gameState.currentPlayer->makeMove(gameState.board, row, col))
            {
                int winCase, winIdx;
                if(gameState.board.hasSomeoneWin(gameState.currentPlayer, winCase, winIdx))
                {
                    std::cout << "Player: " << gameState.currentPlayer->getSymbol() << " has won!\n";
                    gameState.winInfo.win = true;
                    gameState.winInfo.winCase = winCase;
                    gameState.winInfo.index = winIdx;
                    gameState.gameOver = true;
                };
                gameState.currentPlayer = (gameState.currentPlayer->getSymbol() == 'X') 
                                         ? &gameState.playerO 
                                         : &gameState.playerX;
            }
        }
    }
}