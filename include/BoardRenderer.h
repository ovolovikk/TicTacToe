#pragma once
#include <SDL2/SDL.h>
#include "Board.h"
#include "Colors.h"
#include "AssetManager.h"

class BoardRenderer
{
public:
    BoardRenderer();
    ~BoardRenderer();
    void draw(SDL_Renderer* renderer, int winWidth, int winHeight, const Board& board, AssetManager &assetManager);
private:
};