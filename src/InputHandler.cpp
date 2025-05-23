#include "InputHandler.h"
#include <iostream>

void InputHandler::processEvent(const SDL_Event &event, GameState &gameState, bool &isRunning)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int mouseX = event.button.x;
        int mouseY = event.button.y;
        int col = mouseX / gameState.cellWidth;
        int row = mouseY / gameState.cellHeight;
        if(row >= 0 && row < 3 && col >= 0 && col < 3)
        {
            if(gameState.currentPlayer->makeMove(gameState.board, row, col))
            {
                if(gameState.board.hasSomeoneWin(gameState.currentPlayer))
                {
                    std::cout << "Player: " << gameState.currentPlayer->getSymbol() << " has won!\n";
                    isRunning = false;
                };
                gameState.currentPlayer = (gameState.currentPlayer->getSymbol() == 'X') 
                                         ? &gameState.playerO 
                                         : &gameState.playerX;
            }
        }
    }
}