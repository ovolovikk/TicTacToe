#pragma once
#include "Board.h"
#include "Player.h"
#include <SDL2/SDL.h>

class InputHandler
{
public:
    static bool processEvent(const SDL_Event &event, int cellWidth, int cellHeight, Board &board,
                             Player *&currentPlayer, Player &playerX, Player &player0);
};