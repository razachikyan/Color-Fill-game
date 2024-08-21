#ifndef HERRO_HPP
#define HERRO_HPP

#include <string>
#include <vector>
#include "../Settings.hpp"

using coord = std::vector<int>;
using Path = std::vector<coord>;
using Side = int;

enum Keys
{
    STOP = 0,
    UP = 259,
    RIGHT = 261,
    DOWN = 258,
    LEFT = 260,
    ENTER = 10,
};

class Hero
{
private:
    Position position;

public:
    Hero();
    Position getPosition();
    void go(int action);
    void stop();
    bool canGo(PlaceCoords coords, int action);
private:
    // void writePath(); 
    void goTo(Side side);
    int xDelta, yDelta;
    // Path HeroPath;
};

#endif