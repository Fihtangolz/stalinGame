#ifndef __KEYBOARDHANDLER_H__
#define __KEYBOARDHANDLER_H__
#include <SDL.h>
#include <SDL_events.h>
#include <gameField.hpp> //TODO
#include "gameObject.hpp"

class delegateWASDControll {
public:
	enum direction{UP,DOWN,RIGHT,LEFT,ENTER};
	virtual void moveOdj(const direction f) = 0;
	virtual ~delegateWASDControll(){};
};

class keyboardHandler{
private:
	SDL_Event event;
public:
	delegateWASDControll *delegate;
	void pollEvent();
};

#endif // __KEYBOARDHANDLER_H__
