#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <vector>
#include <string>
#include "ncurses.h"

class Window {
    protected:
    using matrix = std::vector<std::vector<char>>;
    using menu = std::vector<std::string>;
    using levels = std::vector<std::string>;
    public:
    virtual ~Window() {}
    public:
    virtual void drawBoard(const matrix &) const = 0;
    virtual void drawMenu(const menu &,const int selected) const = 0;
    virtual void drawLevels(const levels &,const int selected) const = 0;
    virtual void clean() const = 0;
    virtual int input() const = 0;
};
#endif