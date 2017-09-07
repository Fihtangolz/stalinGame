#include <gameField.hpp>
#include "gameObject.hpp"
#include <SDL2/SDL_ttf.h>
#include <random>
#include <iostream>

void gameField::moveOdj(gameObject *obj, direction f){
   switch (f) {
        case UP:
            if(obj->position.y-1>=0)
            {
                field[obj->position.x][obj->position.y]= nullptr;
                --obj->position.y;
                if(field[obj->position.x][obj->position.y]!= nullptr){
                    field[obj->position.x][obj->position.y]->onAnotherObjEnterOnCell(*obj);
                }
                field[obj->position.x][obj->position.y]=obj;
            }
            break;
        case DOWN:
            if(obj->position.y+1<gridDimensions.h)
            {
                field[obj->position.x][obj->position.y]= nullptr;
                ++obj->position.y;
                if(field[obj->position.x][obj->position.y]!= nullptr){
                    field[obj->position.x][obj->position.y]->onAnotherObjEnterOnCell(*obj);
                }
                field[obj->position.x][obj->position.y]=obj;
            }
            break;
        case RIGHT:
            if(obj->position.x+1<gridDimensions.w)
            {
                field[obj->position.x][obj->position.y]= nullptr;
                ++obj->position.x;
                if(field[obj->position.x][obj->position.y]!= nullptr){
                    field[obj->position.x][obj->position.y]->onAnotherObjEnterOnCell(*obj);
                }
                field[obj->position.x][obj->position.y]=obj;
            }
            break;
        case LEFT:
            if(obj->position.x-1>=0)
            {
                field[obj->position.x][obj->position.y]= nullptr;
                --obj->position.x;
                if(field[obj->position.x][obj->position.y]!= nullptr){
                    field[obj->position.x][obj->position.y]->onAnotherObjEnterOnCell(*obj);
                }
                field[obj->position.x][obj->position.y]=obj;
            }
            break;
    };
}

void gameField::render() {
    for (int i = 0; i < gridDimensions.w; i++) {
        for (int j = 0; j < gridDimensions.h; j++) {
            SDL_Rect pos;
            pos.x = i*tileSize;
            pos.y = j*tileSize;
            pos.w = tileSize;
            pos.h = tileSize;
            SDL_RenderCopy(ren, ground, NULL, &pos);
            if(field[i][j]!= nullptr)
            {
                SDL_Rect pos;
                pos.x = i * tileSize;
                pos.y = j * tileSize;
                pos.w = tileSize;
                pos.h = tileSize;
                SDL_RenderCopy(ren, field[i][j]->tex, NULL, &pos);
            }
        }
    }
}

void gameField::generateObjectsOnMap(){
    std::random_device rd; // obtain a random number from hardware
    static std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<int> distrW(0, gridDimensions.w); // define the range
    std::uniform_int_distribution<int> distrH(0, gridDimensions.h);

    std::uniform_int_distribution<int> distr(0,generationPool.size()-1);

    int rundNumber1 = distrW(eng);
    int rundNumber2 = distrH(eng);
    int rundNumber3 = distr(eng);

    while(field[rundNumber1][rundNumber2] != nullptr){
        rundNumber1 = distrW(eng);
        rundNumber2 = distrH(eng);
    }
    field[rundNumber1][rundNumber2] = generationPool[rundNumber3];
}

void gameField::createMessageOnTopBar(std::string message) {
    //avoidance of double initialization
    if (!TTF_WasInit()) {
        TTF_Init();
    }
    static TTF_Font* Sans = TTF_OpenFont("Andale Mono.ttf", 24);
    static SDL_Color White = {255, 255, 255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = 0;
    Message_rect.y = 0;
    Message_rect.w = message.size()*20;;
    Message_rect.h = 20;

    SDL_RenderCopy(ren, Message, NULL, &Message_rect);
}

void gameField::placeObj(gameObject *obj,const int &x,const int &y){
    field[x][y] = obj;
    obj->position.x=x;
    obj->position.y=y;
}

void gameField::addObjToGenerationPool(gameObject *obj){
    generationPool.push_back(obj);
}
