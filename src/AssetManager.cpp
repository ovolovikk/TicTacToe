#include "AssetManager.h"
#include <SDL2/SDL_image.h>

AssetManager::AssetManager(SDL_Renderer* ren)
    : renderer(ren)
{   
}

AssetManager::~AssetManager()
{
    for(auto &pair : textures)
        SDL_DestroyTexture(pair.second);
}

SDL_Texture* AssetManager::getTexture(const std::string &filePath)
{
    if(textures.find(filePath) == textures.end())
    {
        SDL_Texture* tex = IMG_LoadTexture(renderer, filePath.c_str());
        if(tex)
            textures[filePath] = tex;
        return tex;
    }
    return textures[filePath];
}