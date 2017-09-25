#ifndef GAME_SCREENMANAGER_H
#define GAME_SCREENMANAGER_H

#include <functional>
#include <SDL2/SDL_ttf.h>
#include <SDL_rect.h>
#include <array>
#include <iostream>
#include "game.hpp"
#include "keyboardHandler.hpp"

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

        SDL_RenderCopy(G.ren, Message, nullptr, &Message_rect);
    }
};


class chooseLvl:delegateWASDControll{
    button lvl1, lvl2, lvl3, backward;
    std::array<button,4> K{lvl1, lvl2, lvl3, backward};
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
    std::array<button,4>::iterator it;
public:
    void moveOdj(const direction f) { //TODO rename
        switch(f){
            case DOWN:
                if(it!=K.end()-1){
                    it->unselect(*it);
                    ++it;
                    it->select(*it);
                }
                break;
            case UP:
                if(it!=K.begin()) {
                    it->unselect(*it);
                    --it;
                    it->select(*it);
                }
                break;
            case ENTER:
                it->press(*it);
                break;
        }
    }

    chooseLvl():lvl1("1",
                     {150,20,100,80},
                     [](button& i){i.Color = {100, 240, 100, 240};},
                     [](button& i){i.Color = {255, 255, 255, 255};},
                     [](button& i){
                         std::cout<< "enter lvl1 button" << std::endl;
                     }),
                lvl2("2",
                     {150,100,100,80},
                     [](button& i){i.Color = {100, 240, 100, 240};},
                     [](button& i){i.Color = {255, 255, 255, 255};},
                     [](button& i){
                         std::cout<< "enter lvl2 button" << std::endl;
                     }),
                lvl3("3",
                     {150,180,100,80},
                     [](button& i){i.Color = {100, 240, 100, 240};},
                     [](button& i){i.Color = {255, 255, 255, 255};},
                     [](button& i){
                         std::cout<< "enter lvl3 button" << std::endl;
                     }),
                backward("backward",
                         {150,260,100,80},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [](button& i){
                             std::cout<< "enter backward button" << std::endl;
                             //TODO пока не работает
                         })
    {
        it=K.begin();
        it->Color={100, 240, 100, 240};
    }
};

class mainMenu:delegateWASDControll{
private:
    button startGame, chooseLvl, setting,exit;
    std::array<button,4> K{startGame, chooseLvl, setting, exit};

    bool showMenu = true; //TODO еше один костыль
public:
    void gameLoop(){
        G.keyHandler.delegate = this;
        while(showMenu){ //TODO часть перенести в очередь выполнения
            SDL_RenderClear(G.ren);
            for(auto &i : K){
                i.render();
            }
            G.keyHandler.pollEvent();
            SDL_RenderPresent(G.ren);
        }
    }

private:
    std::array<button,4>::iterator it;
public:
    void moveOdj(const direction f) { //TODO rename. По хорошему делегат должен объявлять приватные свойства
                                        // (хотя наверное и публичные) но тут точно косяк
        switch(f){
            case DOWN:
                if(it!=K.end()-1){
                    it->unselect(*it);
                    ++it;
                    it->select(*it);
                }
                break;
            case UP:
                if(it!=K.begin()) {
                    it->unselect(*it);
                    --it;
                    it->select(*it);
                }
                break;
            case ENTER:
                it->press(*it);
                break;
        }
    }

    mainMenu():startGame("Start Game",
                         {150,20,100,80},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [&](button& i){
                             this->showMenu = false; //TODO завершаеи цикл и начинаем игру, еще одна лыжа в копилку овна
                         }),
               setting  ("Setting",
                         {150,180,100,80},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [](button& i){}),
               exit     ("Exit",
                         {150,260,100,80},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [](button& i){std::exit(EXIT_SUCCESS);}),
               chooseLvl("Choose Lvl",
                         {150,100,100,80},
                         [](button& i){i.Color = {100, 240, 100, 240};},
                         [](button& i){i.Color = {255, 255, 255, 255};},
                         [](button& i){
                             std::cout<< "enter chooseLvl button" << std::endl;
                             class chooseLvl f;
                             f.gameLoop();
                         })
    {
        //init first active menu item
        it=K.begin();
        it->Color={100, 240, 100, 240};
    }
    ~mainMenu(){std::cout<< "enter destructor button" << std::endl;}
};

#endif //GAME_SCREENMANAGER_H
