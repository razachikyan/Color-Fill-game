#include "./ncursesWindow.hpp"

NcursesWindow::NcursesWindow()
{
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    getmaxyx(stdscr, height, width);
    noecho();
}

NcursesWindow::~NcursesWindow()
{
    endwin();
}

void NcursesWindow::drawBoard(const matrix &board) const
{
    clear();
    int startX = 4;
    int startY = 4;
    mvprintw(startX - 1, startY, "");
    for (int i = 0; i < board[0].size(); ++i)
    {
        printw("_");
    }

    printw("\n");
    for (int i = 0; i < board.size(); ++i)
    {
        mvprintw(startX + i, startY, "|");
        for (int j = 0; j < board[0].size() - 1; ++j)
        {
            printw("%c", board[i][j]);
        }
        mvprintw(startX + i, startY + board[0].size(), "|\n");
    }
    mvprintw(startX + board.size() - 1, startY, "");
    printw("|");
    for (int i = 0; i < board[0].size()-1; ++i)
    {
        printw("_");
    }
    refresh();
}

void NcursesWindow::drawMenu(const menu &elections, const int selected) const
{
    clear();

    const int centerHeight = height / 2 - elections.size();
    const int centerWidth = width / 2 - 5;

    for (int i = 0; i < (int)elections.size(); ++i)
    {
        if (selected == i)
        {
            mvprintw(centerHeight + i, centerWidth, ">%s\n", elections[i].c_str());
        }
        else
        {
            mvprintw(centerHeight + i, centerWidth, " %s\n", elections[i].c_str());
        }
    }
    refresh();
}

void NcursesWindow::drawLevels(const levels &elections, const int selected) const
{
    clear();

    const int centerHeight = height / 2 - elections.size();
    const int centerWidth = width / 2 - 5;

    for (int i = 0; i < (int)elections.size(); ++i)
    {
        if (selected == i)
        {
            mvprintw(centerHeight + i, centerWidth, ">%s\n", elections[i].c_str());
        }
        else
        {
            mvprintw(centerHeight + i, centerWidth, " %s\n", elections[i].c_str());
        }
    }
    refresh();
}

int NcursesWindow::input() const
{
    return getch();
}

void NcursesWindow::clean() const
{
    clear();
}