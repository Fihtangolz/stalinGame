#ifndef GAME_GAMEOBJECT_H_
#define GAME_GAMEOBJECT_H_

#include <SDL_render.h>
#include <functional>

class gameObject{
private:
    //UI
    int type;
    SDL_Texture *tex;
public:
    struct {
        int x;
        int y;
    }position;
    gameObject(const int &tp,SDL_Texture* txr){
        type = tp;
        tex = txr;
    };
    std::function<void(gameObject&)> onAnotherObjEnterOnCell;
};

#endif //GAME_GAMEOBJECT_H_
