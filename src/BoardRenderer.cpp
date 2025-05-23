#include "BoardRenderer.h"
#include <SDL2_gfxPrimitives.h>

BoardRenderer::BoardRenderer()
{
}
BoardRenderer::~BoardRenderer()
{
}

void BoardRenderer::drawBackground(SDL_Renderer* renderer, int winWidth, int winHeight,
                                   Uint8 topR, Uint8 topG, Uint8 topB,
                                   Uint8 bottomR, Uint8 bottomG, Uint8 bottomB)
{
    for (int y = 0; y < winHeight; ++y)
    {
        float factor = static_cast<float>(y) / (winHeight - 1);
        Uint8 r = static_cast<Uint8>(topR * (1 - factor) + bottomR * factor);
        Uint8 g = static_cast<Uint8>(topG * (1 - factor) + bottomG * factor);
        Uint8 b = static_cast<Uint8>(topB * (1 - factor) + bottomB * factor);
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderDrawLine(renderer, 0, y, winWidth, y);
    }
}

void BoardRenderer::drawGrid(SDL_Renderer* renderer, int winWidth, int winHeight, int thickness)
{
    int cellWidth = winWidth / 3;
    int cellHeight = winHeight / 3;

    for (int i = 1; i < 3; ++i)
    {
        int x = i * cellWidth;
        thickLineRGBA(renderer, x, 0, x, winHeight, thickness, 145, 208, 241, 255);
    }

    for (int i = 1; i < 3; ++i)
    {
        int y = i * cellHeight;
        thickLineRGBA(renderer, 0, y, winWidth, y, thickness, 145, 208, 241, 255);
    }
}

void BoardRenderer::drawX(SDL_Renderer* renderer, int x, int y, int cellWidth, int cellHeight, int thickness)
{
    thickLineRGBA(renderer,
                    x + 10, y + 10,
                    x + cellWidth - 10, y + cellHeight - 10,
                    thickness, 255, 0, 0, 255);
    thickLineRGBA(renderer,
                    x + cellWidth - 10, y + 10,
                    x + 10, y + cellHeight - 10,
                    thickness, 255, 0, 0, 255);
}

void BoardRenderer::drawO(SDL_Renderer* renderer, int x, int y, int cellWidth, int cellHeight, int thickness)
{
    int centerX = x + cellWidth / 2;
    int centerY = y + cellHeight / 2;
    int radius = ((cellWidth < cellHeight ? cellWidth : cellHeight) / 2) - 10;
    thickCircle(renderer, centerX, centerY, radius, 0, 0, 255, 255, thickness);
}

void BoardRenderer::draw(SDL_Renderer* renderer, int winWidth, int winHeight, const Board& board) {
    int thickness = 5;

    drawBackground(renderer, winWidth, winHeight, 245, 245, 220, 222, 207, 190);

    drawGrid(renderer, winWidth, winHeight, thickness);

    int cellWidth = winWidth / 3;
    int cellHeight = winHeight / 3;

    for(int row = 0; row < 3; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
            int cellX = col * cellWidth;
            int cellY = row * cellHeight;
            char symbol = board.getCell(row, col);
            if(symbol == 'X')
                drawX(renderer, cellX, cellY, cellWidth, cellHeight, thickness);
            else if (symbol == '0')
                drawO(renderer, cellX, cellY, cellWidth, cellHeight, thickness);
        }
    }
}

void BoardRenderer::thickCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int thickness)
{
    for(int i = 0; i < thickness; ++i)
        circleRGBA(renderer, centerX, centerY, radius - i, r, g, b, a);
}
