#include "./Hero.hpp"

Hero::Hero(): position({1, 1}) {}


void Hero::goTo(Side side) {
    switch(side) {
        case Keys::UP:
            yDelta = -1;
            xDelta = 0;
            break;
        case Keys::RIGHT:
            xDelta = 1;
            yDelta = 0;
            break;
        case Keys::DOWN:
            yDelta = 1;
            xDelta = 0;
            break;
        case Keys::LEFT: 
            xDelta = -1;
            yDelta = 0;
    }
}
 
// void Hero::writePath() {
//     HeroPath.push_back({position.y, position.x});
// } 


void Hero::go(int action)
{   
    goTo(action);
    position.x += xDelta;
    position.y += yDelta;
}

void Hero::stop()
{
    xDelta = 0;
    yDelta = 0;
}

Position Hero::getPosition() {
    return position;
}

bool Hero::canGo(PlaceCoords coords, int action) {
    switch(action) {
        case Keys::UP:
            if(position.y - 1 < 1) {
                return false;
            }
            break;
        case Keys::RIGHT:
            if(position.x >= coords.width-3) {
                return false;
            }
            break;
        case Keys::DOWN:
            if(position.y >= coords.height - 3) {
                return false;
            }
            break;
        case Keys::LEFT: 
            if(position.x - 1 < 1) {
                return false;
            }
    }
    return true;
}