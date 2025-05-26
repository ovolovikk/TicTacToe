#include "BoardRenderer.h"
#include <algorithm>

BoardRenderer::BoardRenderer()
{
}

BoardRenderer::~BoardRenderer()
{
}

void BoardRenderer::draw(SDL_Renderer* renderer, int winWidth, int winHeight, const Board& board, AssetManager &assetManager)
{
    // Draw the full-screen clean background.
    SDL_Texture* cleanTex = assetManager.getTexture("assets/clean_screen_texture.png");
    if(cleanTex)
        SDL_RenderCopy(renderer, cleanTex, nullptr, nullptr);

    // Load the board texture (which will nearly fill the screen)
    SDL_Texture* boardTex = assetManager.getTexture("assets/board_texture.png");
    if (!boardTex)
        return;

    // Get intrinsic board texture dimensions.
    int boardW, boardH;
    SDL_QueryTexture(boardTex, nullptr, nullptr, &boardW, &boardH);

    float scale = 0.98f * std::min(winWidth / static_cast<float>(boardW), winHeight / static_cast<float>(boardH));
    int newBoardW = static_cast<int>(boardW * scale);
    int newBoardH = static_cast<int>(boardH * scale);

    // Center the board texture in the window.
    SDL_Rect boardRect;
    boardRect.w = newBoardW;
    boardRect.h = newBoardH;
    boardRect.x = (winWidth - newBoardW) / 2;
    boardRect.y = (winHeight - newBoardH) / 2;

    SDL_RenderCopy(renderer, boardTex, nullptr, &boardRect);

    // Draw the moves ('X' and '0') on top of the board.
    SDL_Texture* xTex = assetManager.getTexture("assets/x_texture.png");
    SDL_Texture* oTex = assetManager.getTexture("assets/0_texture.png");

    // Each cell size is based on the drawn board texture.
    int cellW = boardRect.w / 3;
    int cellH = boardRect.h / 3;

    // Use moveScale = 0.8 to have moves occupy 80% of a cell.
    const float moveScale = 0.8f;
    int moveW = static_cast<int>(cellW * moveScale);
    int moveH = static_cast<int>(cellH * moveScale);

    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            char symbol = board.getCell(row, col);
            SDL_Texture* moveTex = nullptr;
            if (symbol == 'X')
                moveTex = xTex;
            else if (symbol == '0')
                moveTex = oTex;

            if (moveTex)
            {
                // Compute cell center based on boardRect.
                int cellCenterX = boardRect.x + col * cellW + cellW / 2;
                int cellCenterY = boardRect.y + row * cellH + cellH / 2;

                // Center move texture in the cell.
                int dx = cellCenterX - moveW / 2;
                int dy = cellCenterY - moveH / 2;

                SDL_Rect moveRect = { dx, dy, moveW, moveH };
                SDL_RenderCopy(renderer, moveTex, nullptr, &moveRect);
            }
        }
    }
}