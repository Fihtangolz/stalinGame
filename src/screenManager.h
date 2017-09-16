#ifndef GAME_SCREENMANAGER_H
#define GAME_SCREENMANAGER_H

#include <functional>
#include <search.h>
#include <SDL2/SDL_ttf.h>
#include <SDL_rect.h>
#include <array>
#include "game.hpp"

extern game G;

class button{
private:

public:
    std::string text;
    SDL_Rect Message_rect; //TODO must private (and how create function whos now this???
    SDL_Color Color;

    std::function<void(button&)> select;
    std::function<void(button&)> unselect;
    std::function<void(button&)> press;

    button(std::string renderText, SDL_Rect _rect,std::function<void(button&)> _select, std::function<void(button&)> _unselect, std::function<void(button&)> _press):
            text(renderText),select(_select),unselect(_unselect),press(_press),Message_rect(_rect),Color({255, 255, 255, 255}){}

    void render() const {
        TTF_Font* Sans = TTF_OpenFont("Andale Mono.ttf", 24); // TODO можно хэшировать в ресурс менеджере в конечном итоге интерфейс неизменен
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), Color);
        SDL_Texture* Message = SDL_CreateTextureFromSurface(G.ren, surfaceMessage);

        SDL_RenderCopy(G.ren, Message, NULL, &Message_rect);
    }
};

class mainMenu:delegateWASDControll{
    button startGame, chooseLvl, setting,exit;
    std::array<button,4> K{startGame, chooseLvl, setting, exit};


public:
    void gameLoop(){
        G.keyHandler.delegate = this;
        while(true){ //TODO часть перенести в очередь выполнения
            SDL_RenderClear(G.ren);
            for(auto &i : K){
                i.render();
            }
            G.keyHandler.pollEvent();
            SDL_RenderPresent(G.ren);
        }
    }

private:
    std::array<button,4>::iterator it = K.begin();
public:
    void moveOdj(const direction f) { //TODO rename
        switch(f){
            case UP:
                it->unselect(*it);
                ++it;
                it->select(*it);
                break;
            case DOWN:
                it->unselect(*it);
                --it;
                it->select(*it);
                break;
            case ENTER:
                it->press(*it);
                break;
        }
    }

    mainMenu():startGame("Start Game",
                         {150,20,100,80},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){}),
               setting  ("Setting",
                         {150,100,100,80},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){}),
               exit     ("Exit",
                         {150,180,100,80},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){}),
               chooseLvl("Choose Lvl",
                         {150,260,100,80},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){}){}
};

/*
class chooseLvl{

    std::vector<level> P;
    chooseLvl(){

    }
    render(){
    /for (int i = 0; i < gridDimensions.w; i++) {
        for (int j = 0; j < gridDimensions.h; j++) {
            SDL_Rect pos;
            pos.x = i*tileSize;
            pos.y = j*tileSize;
            pos.w = tileSize;
            pos.h = tileSize;
            SDL_RenderCopy(ren, ground, NULL, &pos);
        }
       }
    }
}; */

#endif //GAME_SCREENMANAGER_H
