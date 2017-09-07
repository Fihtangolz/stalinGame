#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL_video.h>
#include <SDL_render.h>
#include <ostream>
#include <iostream>
#include <SDL.h>
#include "resourceManage.hpp"
#include "gameField.hpp"
#include "keyboardHandler.hpp"

class game{
private:
    SDL_Window *win;

public:
    SDL_Renderer *ren;

    resourceManager resManager;
    gameField gField;
    keyboardHandler keyHandler;
    game();
    ~game();
};

game::game()
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        //return EXIT_FAILURE;
    }

    win = SDL_CreateWindow("Simple Game", 100, 100, 400, 400, SDL_WINDOW_POPUP_MENU);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        //return EXIT_FAILURE;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr){
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        //return EXIT_FAILURE;
    }
    resManager.ren = ren;
    gField.ren = ren;
}

game::~game(){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
#endif //GAME_GAME_H
