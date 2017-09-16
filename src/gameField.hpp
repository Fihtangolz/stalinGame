#ifndef __GAMEFIELD_H__
#define __GAMEFIELD_H__
#include <SDL.h>
#include <SDL_events.h>
#include <string>
#include <vector>
#include "gameObject.hpp"

class gameField {
private:
    struct {
        int w=10;
        int h=10;
    }gridDimensions;
    const int tileSize = 40;

    gameObject *field[10][10] = {{0}};

    std::vector<gameObject*> generationPool;
public:
    enum direction{DOWN, UP, RIGHT, LEFT};

    SDL_Renderer *ren;
    SDL_Texture *ground;
    void createMessageOnTopBar( std::string message);
    void render();
    void moveOdj(gameObject *obj, direction f);
    void generateObjectsOnMap();
    void addObjToGenerationPool(gameObject *obj);
    void placeObj(gameObject &obj, const int &x, const int &y);
};

#endif // __GAMEFIELD_H__