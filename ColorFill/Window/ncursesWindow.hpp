#ifndef NECURSES_WINDOW_HPP
#define NECURSES_WINDOW_HPP
#include "./window.hpp"
#include "../Settings.hpp"

class NcursesWindow:public Window {
    public: 
    NcursesWindow();
    ~NcursesWindow();
    public:
    void drawBoard(const matrix &) const;
    void drawMenu(const menu &,const int selected) const;
    void drawLevels(const levels &,const int selected) const;
    int input() const;
    void clean() const;
    private: 
    int height;
    int width;
};

#endif