#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>

class AssetManager
{
public:
    AssetManager(SDL_Renderer* renderer);
    ~AssetManager();

    SDL_Texture* getTexture(const std::string &filePath);
private:
    SDL_Renderer* renderer;
    std::unordered_map<std::string, SDL_Texture*> textures;
};