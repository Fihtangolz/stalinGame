#ifndef __RESOURCE_MANAGE_H__
#define __RESOURCE_MANAGE_H__
#include <SDL.h>
#include <SDL_events.h>
#include <vector>
#include <string>
#include <iostream>


class resourceManager {
private:
    std::vector<SDL_Texture*> LTexturs;
public:
    SDL_Renderer *ren;
    SDL_Texture* createTextureFromBMP(const std::string &path);
    ~resourceManager();
};

resourceManager::~resourceManager(){
    for(auto *i:LTexturs) {
        SDL_DestroyTexture(i);
    }
}

SDL_Texture* resourceManager::createTextureFromBMP(const std::string &path){
    SDL_Surface *bmp = SDL_LoadBMP(path.c_str());
    if (bmp == nullptr){
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr){
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    LTexturs.push_back(tex);
    return tex;
}
#endif // __RESOURCE_MANAGER_H__