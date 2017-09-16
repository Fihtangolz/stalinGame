#include <iostream>
#include "keyboardHandler.hpp"

void keyboardHandler::pollEvent() {
      if (SDL_PollEvent(&event)) {
          if(event.type == SDL_KEYDOWN) {
              switch(event.key.keysym.scancode){
                  case SDL_SCANCODE_W:
                      delegate->moveOdj(delegateWASDControll::UP);
                      break;
                  case SDL_SCANCODE_S:
                      delegate->moveOdj(delegateWASDControll::DOWN);
                      break;
                  case SDL_SCANCODE_A:
                      delegate->moveOdj(delegateWASDControll::LEFT);
                      break;
                  case SDL_SCANCODE_D:
                      delegate->moveOdj(delegateWASDControll::RIGHT);
                      break;
                  case 40: //in mac it is enter
                      delegate->moveOdj(delegateWASDControll::ENTER);
                      break;
              }
          }
      }
}


