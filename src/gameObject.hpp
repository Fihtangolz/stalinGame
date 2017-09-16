#ifndef GAME_GAMEOBJECT_H_
#define GAME_GAMEOBJECT_H_

#include <SDL_render.h>
#include <functional>

//GOF prototype with in code discription
class gameObject{
private:

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
