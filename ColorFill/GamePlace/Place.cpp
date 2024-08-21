#include "./Place.hpp"

GamePlace::GamePlace() {
    init();
}

void GamePlace::drawTail(Position position)
{
    board[position.y][position.x] = '.';
}

void GamePlace::setSize(int width, int height) {
    this->height = height;
    this->width = width; 
    init();
}

PlaceCoords GamePlace::getCoords() const
{
    return {4, 4, width, height};
}

void GamePlace::drawHero(Position position)
{
    if (board[position.y][position.x] == '.')
    {
        fillBoard();
    }
    if (board[position.y][position.x] == ' ')
    {
        filled++;
    }
    board[position.y][position.x] = '@';
}
void GamePlace::fillBoard()
{
    fillOuter(0, 0);
    
    fillInnerRemoveOuter();
}
void GamePlace::fillOuter(int x, int y)
{
    board[x][y] = '1';
    if (y + 1 < board[0].size() && board[x][y + 1] == ' ')
    {
        fillOuter(x, y + 1);
    }
    if (y - 1 >= 0 && board[x][y - 1] == ' ')
    {
        fillOuter(x, y - 1);
    }
    if (x + 1 < board.size() && board[x + 1][y] == ' ')
    {
        fillOuter(x + 1, y);
    }
    if (x - 1 >= 0 && board[x - 1][y] == ' ')
    {
        fillOuter(x - 1, y);
    }
}
void GamePlace::fillInnerRemoveOuter()
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] == '1')
            {
                board[i][j] = ' ';
            }
            else if (board[i][j] == ' ')
            {
                board[i][j] = '#';
                filled++;
            }
        }
    }
}

bool GamePlace::isFinish() const
{
    const int height = this->height - 3;
    const int width = this->width - 3;
    return (filled >= height * width - 1);
}

void GamePlace::init() {
    board = Board(height, std::vector<char>(width, ' '));
}

GamePlace::Board GamePlace::getMatrix() const
{
    return board;
}

void GamePlace::cleanBoard()
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            board[i][j] = ' ';
        }
    }
    filled = 0;
}