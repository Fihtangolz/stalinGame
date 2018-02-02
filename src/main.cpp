#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <SDL2/SDL_ttf.h>
#include "game.hpp"
#include "screenManager.h"
#include "timers.hpp"

//MinGW resolve trouble
namespace patch
{
	template < typename T > std::string to_string( const T& n )
	{
		std::ostringstream stm ;
		stm << n ;
		return stm.str() ;
	}
}
/*
void func() {
    std::fstream gResult("gResult.txt",std::ios::in | std::ios::out | std::ios::app);
    gResult<<std::setw(8)<<std::setfill('0')<<patch::to_string(tick / 100)<<std::setw(8)<<std::setfill('0')<<patch::to_string(score)<<std::endl;
    std::vector<std::pair<int,int>> rTbl;
    std::pair<int,int> i;
    std::string str;
    gResult.seekg(0);
    while(std::getline(gResult,str))
    {
    i.first=std::stoi(str.substr(0,8));
    i.second=std::stoi(str.substr(8,8));
    std::cout<<i.first<<": "<<i.second<<std::endl;
    rTbl.push_back(i); }
    std::sort(rTbl.begin(), rTbl.end(),[](std::pair<int,int> i,std::pair<int,int> j){
        return (i.second>j.second);
    });
SDL_RenderClear(G.ren);

SDL_Rect Message_rect;
Message_rect.x = 0;
Message_rect.y = 0;
Message_rect.h = 20;
int p=0;
G.gField.createMessageOnTopBar("Communism has failed.");
for (auto &i:rTbl)
{
	if(p==10){ break;}
	static TTF_Font* Sans = TTF_OpenFont("Andale Mono.ttf", 24);
	static SDL_Color White = {255, 255, 255};
	std::string m = "time: " + patch::to_string(i.first) + " score: " + patch::to_string(i.second);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, m.c_str(), White);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(G.ren, surfaceMessage);

	Message_rect.y +=20;
	Message_rect.w = m.size()*20;

	SDL_RenderCopy(G.ren, Message, NULL, &Message_rect);
	p++;
}
}*/

int main(int argc, char *argv[]) {
    mainMenu L;
    L.gameLoop();
	SDL_Texture* tex1 = G.resManager.createTextureFromBMP("img/grass.bmp");
	SDL_Texture* tex2 = G.resManager.createTextureFromBMP("img/clock.bmp");
	SDL_Texture* tex3 = G.resManager.createTextureFromBMP("img/hero.bmp");
	SDL_Texture* tex4 = G.resManager.createTextureFromBMP("img/mushroom.bmp");
	SDL_Texture* tex5 = G.resManager.createTextureFromBMP("img/bomb.bmp");
	SDL_Texture* tex6 = G.resManager.createTextureFromBMP("img/bomb.bmp");
	SDL_Texture* tex7 = G.resManager.createTextureFromBMP("img/bomb.bmp");

	G.gField.ground = tex1;

	enum gameObjectType{heroT,doorT,clockT,mushroomT,littleCheeseT,bigCheeseT};

	int score=0;
	bool gameOver = false;
	int tick = 10000;
	bool timeRun = true;

	gameObject  hero(heroT,tex3);
	gameObject  door{doorT,tex5};
	gameObject  clock{clockT,tex2};
	gameObject  mushroom{mushroomT,tex4};
	gameObject  littleCheese{littleCheeseT,tex6};
	gameObject  bigCheese{bigCheeseT,tex7};

	G.gField.placeObj(hero,0,0);

    door.onAnotherObjEnterOnCell=[&gameOver](gameObject &obj){
		if (obj.GType == heroT){
			gameOver = true;
		}
	};
	//TODO заморозка времени сделанна через срань колоду, но лучше так чем никак
	std::mutex mut;
	clock.onAnotherObjEnterOnCell=[&timeRun,&mut](gameObject &obj){
		if (obj.GType == heroT){
			timeRun = false;
			//Предотвращаем игры со временем, чет рик и морти вспомнились со своим "не играй со временем сука",
			//по хорошему время фриза надо складвать, но это фитча а не баг
			mut.lock();
			later freezTime(1000, false, [&timeRun](){timeRun = true;});
			mut.unlock();
		}
	};
	mushroom.onAnotherObjEnterOnCell=[&tick](gameObject &obj){
		//Созданим мигатор, время жизни обозначим через тики
		if(tick%20==0){
			SDL_RenderClear(G.ren);
		}

    };

	littleCheese.onAnotherObjEnterOnCell=[&score](gameObject &obj){
		if(obj.GType == heroT){
			score+=10;
		}
	};

	bigCheese.onAnotherObjEnterOnCell=[&score](gameObject &obj){

		if(obj.GType == heroT){
			score+=40;
		}
	};

	G.gField.addObjToGenerationPool(&door);
	G.gField.addObjToGenerationPool(&clock);
	G.gField.addObjToGenerationPool(&mushroom);
	G.gField.addObjToGenerationPool(&bigCheese);
	G.gField.addObjToGenerationPool(&littleCheese);

	hero.container = &G.gField;
	G.keyHandler.delegate= static_cast<delegateWASDControll*>(&hero);

	while(tick > 0 && !gameOver) //TODO вопрос с внутри игровым временем хорош но достоин отдельной статьи
    {
	    SDL_RenderClear(G.ren);
	    G.gField.render();
	    G.keyHandler.pollEvent();
		//Сдесь происходит вызов функции объекта
	    if(tick%100==0){
            G.gField.generateObjectsOnMap();
	    }
	    G.gField.createMessageOnTopBar("time: " + patch::to_string(tick / 100) + " score: " + patch::to_string(score));
	    SDL_RenderPresent(G.ren);
        if(timeRun){
			--tick;
		}
    }
}

