#include <iostream>
#include "keyboardHandler.hpp"

void keyboardHandler::pollEvent(gameField &f) {
		if (SDL_PollEvent(&event))
      {
			 if (event.type == SDL_KEYDOWN)
			 {
				 //pressed W
				 if(event.key.keysym.scancode == 26)
				 {
					f.moveOdj(puppet,UP);
				 }
				 //pressed S
				 if(event.key.keysym.scancode == 22)
				 {
					 f.moveOdj(puppet,DOWN);
				 }
				 //pressed A
				 if(event.key.keysym.scancode == 4)
				 {
					 f.moveOdj(puppet,LEFT);
				 }
				 //pressed D
				 if(event.key.keysym.scancode == 7)
				 {
					 f.moveOdj(puppet, RIGHT);
				 }
				 //pressed Q
				 if(event.key.keysym.scancode == 20)
				 {
					 std::cout<<"pressed Q";
				 }
			 }
      }
}

void keyboardHandler::setObjForControll(gameObject *obj) {
	puppet = obj;
}
