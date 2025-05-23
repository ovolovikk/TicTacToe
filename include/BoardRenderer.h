#pragma once
#include <SDL2/SDL.h>
#include "Board.h"

class BoardRenderer
{
public:
    BoardRenderer();
    ~BoardRenderer();
    void draw(SDL_Renderer* renderer, int winWidth, int winHeight, const Board& board);
private:
    void drawBackground(SDL_Renderer* renderer, int winWidth, int winHeight,
                        Uint8 topR, Uint8 topG, Uint8 topB,
                        Uint8 bottomR, Uint8 bottomG, Uint8 bottomB);
    void drawGrid(SDL_Renderer* renderer, int winWidth, int winHeight, int thickness);
    void drawX(SDL_Renderer* renderer, int x, int y, int cellWidth, int cellHeight, int thickness);
    void drawO(SDL_Renderer* renderer, int x, int y, int cellWidth, int cellHeight, int thickness);
    void thickCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, 
                     Uint8 r, Uint8 g, Uint8 b, Uint8 a, int thickness);
};