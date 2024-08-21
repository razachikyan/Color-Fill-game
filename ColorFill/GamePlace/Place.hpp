#ifndef PLACE_HPP
#define PLACE_HPP

#include <vector>
#include "../Settings.hpp"

using FilledBlocks = std::vector<std::vector<int>>;

class GamePlace
{
private: 
    using Board = std::vector<std::vector<char>>;
    int height = 15;
    int width = 30;
    Board board;
    int filled = 0;
public:
    GamePlace();
    void drawHero(Position position);
    void drawTail(Position position);
    void setSize(int height, int width);
    PlaceCoords getCoords() const;
    void fillBoard();
    void init();
    void cleanBoard();
    void fillOuter(int x, int y);
    void fillInnerRemoveOuter();
    bool isFinish() const;
    Board getMatrix() const;
};

#endif