#ifndef __KEYBOARDHANDLER_H__
#define __KEYBOARDHANDLER_H__
#include <SDL.h>
#include <SDL_events.h>
#include <gameField.hpp> //TODO

class keyboardHandler{
private:
	SDL_Event event;
	gameObject *puppet;
public:
	 void pollEvent(gameField &f);
	 void setObjForControll(gameObject *obj);
};

#endif // __KEYBOARDHANDLER_H__
