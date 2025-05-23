#include "BoardRenderer.h"
#include <SDL2_gfxPrimitives.h>

BoardRenderer::BoardRenderer()
{
}
BoardRenderer::~BoardRenderer()
{
}

void BoardRenderer::drawBackground(SDL_Renderer* renderer, int winWidth, int winHeight,
                                   const Color &topColor, const Color &bottomColor)
{
    for (int y = 0; y < winHeight; ++y)
    {
        float factor = static_cast<float>(y) / (winHeight - 1);
        Uint8 r = static_cast<Uint8>(topColor.r * (1 - factor) + bottomColor.r * factor);
        Uint8 g = static_cast<Uint8>(topColor.g * (1 - factor) + bottomColor.g * factor);
        Uint8 b = static_cast<Uint8>(topColor.b * (1 - factor) + bottomColor.b * factor);
        Uint8 a = static_cast<Uint8>(topColor.a * (1 - factor) + bottomColor.a * factor);
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
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
    Color blue(0, 0, 255, 255);
    thickCircle(renderer, centerX, centerY, radius, blue, thickness);
}

void BoardRenderer::draw(SDL_Renderer* renderer, int winWidth, int winHeight, const Board& board) {
    int thickness = 5;

    Color topColor(245, 245, 220);
    Color bottomColor(222, 207, 190);
    drawBackground(renderer, winWidth, winHeight, topColor, bottomColor);

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

void BoardRenderer::thickCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, const Color &color, int thickness)
{
    for(int i = 0; i < thickness; ++i)
        circleRGBA(renderer, centerX, centerY, radius - i, color.r, color.g, color.b, color.a);
}
