#pragma once
#include "Board.h"
#include "Player.h"
#include "GameState.h"
#include <SDL2/SDL.h>

class InputHandler
{
public:
    static void processEvent(const SDL_Event &event, GameState &gameState, bool &isRunning);
};