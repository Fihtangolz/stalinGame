#ifndef GAME_GAMEOBJECT_H_
#define GAME_GAMEOBJECT_H_

#include <SDL_render.h>
#include <functional>

//GOF prototype
class gameObject{
private:
    //UI
    SDL_Texture *tex;
public:
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
