#pragma once
#include "GameState.h"
#include "BoardRenderer.h"
#include "InputHandler.h"
#include <SDL2/SDL.h>

class GameController {
public:
    GameController(int winWidth, int winHeight);
    // runs game, takes renderer from SDLWindow
    void run(SDL_Renderer* renderer);

private:
    GameState gameState;
    BoardRenderer boardRenderer;
};