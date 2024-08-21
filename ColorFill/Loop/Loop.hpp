#ifndef LOOP_HPP
#define LOOP_HPP
#include <vector>
#include "../GamePlace/Place.hpp"
#include "../Window/ncursesWindow.hpp"
#include "../Hero/Hero.hpp"

class Loop
{
using Menu = std::vector<std::string>;    
public:
    Loop(Hero &NewHero, GamePlace &board);
    ~Loop();
    void play(int level);
    void menu();
    void options();
private:
    Hero &hero;
    const Window *win;
    GamePlace& board;
};

#endif