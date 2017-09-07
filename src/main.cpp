#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <SDL2/SDL_ttf.h>
#include "game.hpp"


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
}//test git

int main(int argc, char *argv[]) {
	game G;
	SDL_Texture* tex1 = G.resManager.createTextureFromBMP("img/grass.bmp");
	SDL_Texture* tex2 = G.resManager.createTextureFromBMP("img/clock.bmp");
	SDL_Texture* tex3 = G.resManager.createTextureFromBMP("img/hero.bmp");
	SDL_Texture* tex4 = G.resManager.createTextureFromBMP("img/mushroom.bmp");
	SDL_Texture* tex5 = G.resManager.createTextureFromBMP("img/bomb.bmp");

	G.gField.ground = tex1;

	enum gameObjectType{heroT,bombT,clockT,mushroomT};

	int score=0;
	bool gameOver = false;
	int tick = 10000;
	gameObject  hero(heroT,tex3);
	gameObject  bomb{bombT,tex5};
	gameObject  clock{clockT,tex2};
	gameObject  mushroom{mushroomT,tex4};

	G.gField.placeObj(&hero,0,0);

    bomb.onAnotherObjEnterOnCell=[&gameOver](gameObject &obj)
	{
		if (obj.type == heroT)
		{
			gameOver = true;
		}
	};
	clock.onAnotherObjEnterOnCell=[&tick](gameObject &obj){
		if (obj.type == heroT)
		{
			tick += 10 * 100;
		}
	};
	mushroom.onAnotherObjEnterOnCell=[&score](gameObject &obj)
	{
		score += 12;

	};

	G.gField.addObjToGenerationPool(&bomb);
	G.gField.addObjToGenerationPool(&clock);
	G.gField.addObjToGenerationPool(&mushroom);

	G.keyHandler.setObjForControll(&hero);
for (; tick > 0 && !gameOver; --tick)
{
	SDL_RenderClear(G.ren);
	G.gField.render();
	G.keyHandler.pollEvent(G.gField);
	if(tick%100==0){
        std::cout<<tick%100<<std::endl;
        G.gField.generateObjectsOnMap();
	}
	G.gField.createMessageOnTopBar("time: " + patch::to_string(tick / 100) + " score: " + patch::to_string(score));
	SDL_RenderPresent(G.ren);
	SDL_Delay(1);
}

	return EXIT_SUCCESS;
}
