#include "gameObject.hpp"

void gameObject::moveOdj(direction f) {   //TODO кусок костыля от дилегата
    switch(f){ //TODO тут вопрос проектирования нажатия кнопок и направления в начале были разными сущностями теперь одна но косяк остался
        case UP:
            container->moveOdj(this,gameField::direction::UP);
            break;
        case DOWN:
            container->moveOdj(this,gameField::direction::DOWN);
            break;
        case LEFT:
            container->moveOdj(this,gameField::direction::LEFT);
            break;
        case RIGHT:
            container->moveOdj(this,gameField::direction::RIGHT);
            break;
    }

}

gameObject::gameObject(const int &tp,SDL_Texture* txr){
    GType = tp;
    tex = txr;
}
