#pragma clang diagnostic push
#pragma ide diagnostic ignored "CannotResolve"
#ifndef GAME_GAMEOBJECT_H_
#define GAME_GAMEOBJECT_H_

#include <SDL_render.h>
#include <functional>
#include "keyboardHandler.hpp"
#include "gameField.hpp"
#include "gameObject.hpp"

class gameField;

//GOF prototype with in code discription
class gameObject: public delegateWASDControll{ //TODO не красивое решение со стороны архитектуры, ну что тут поделаешь
public:
    gameField* container;
    void moveOdj(const direction f);
    ////////////////////////
    //UI
    SDL_Texture *tex;
    int GType;
    struct {
        int x;
        int y;
    }position;
    gameObject(const int &tp,SDL_Texture* txr);
    std::function<void(gameObject&)> onAnotherObjEnterOnCell;
};



#endif //GAME_GAMEOBJECT_H_

#pragma clang diagnostic pop