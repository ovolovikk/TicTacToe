#pragma once
#include <SDL2/SDL.h>
#include "Board.h"
#include "Colors.h"

class BoardRenderer
{
public:
    BoardRenderer();
    ~BoardRenderer();
    void draw(SDL_Renderer* renderer, int winWidth, int winHeight, const Board& board);
private:
    void drawBackground(SDL_Renderer* renderer, int winWidth, int winHeight,
                        const Color &topColor, const Color &bottomColor);
    void drawGrid(SDL_Renderer* renderer, int winWidth, int winHeight, int thickness);
    void drawX(SDL_Renderer* renderer, int x, int y, int cellWidth, int cellHeight, int thickness);
    void drawO(SDL_Renderer* renderer, int x, int y, int cellWidth, int cellHeight, int thickness);
    void thickCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, 
                     const Color &color, int thickness);
};