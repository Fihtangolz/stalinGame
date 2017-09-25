#pragma clang diagnostic push
#pragma ide diagnostic ignored "CannotResolve"
#ifndef GAME_GAMEOBJECT_H_
#define GAME_GAMEOBJECT_H_

#include <SDL_render.h>
#include <functional>
#include "screenManager.h"
#include "keyboardHandler.hpp"
#include "game.hpp"

//GOF prototype with in code discription
class gameObject : delegateWASDControll { //TODO наследование от делегата управление тоже не хорошо и костыль,
                                         // но мы пляшем дальше
public:
    //UI
    SDL_Texture *tex;
    int GType;
    struct {
        int x;
        int y;
    }position;
    gameObject(const int &tp,SDL_Texture* txr){
        GType = tp;
        tex = txr;
    };
    std::function<void(gameObject&)> onAnotherObjEnterOnCell;
};

#endif //GAME_GAMEOBJECT_H_

#pragma clang diagnostic pop