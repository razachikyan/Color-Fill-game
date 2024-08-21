#include "./Loop.hpp"

Loop::Loop(Hero &NewHero, GamePlace &board) : hero(NewHero), board(board), win(new NcursesWindow()) {}

void Loop::play(int level)
{
    PlaceCoords boardCoords{4, 4, (15 + level*5)*2, 15 + level*5};
    win->clean();
    board.setSize((15 + level*5)*2, 15 + level*5);
    while (true)
    {
        win->drawBoard(board.getMatrix());
        int action = win->input();
        if (hero.canGo(boardCoords, action))
        {
            board.drawTail(hero.getPosition());
            hero.go(action);
            board.drawHero(hero.getPosition());
        }
        if (board.isFinish())
        {
            board.cleanBoard();
            break;
        }
    }
}

void Loop::menu()
{
    const Menu gameMenu = {
        "Play",
        "Levels",
        "Exit",
    };

    int selected = 0;
    bool exit = false;
    while (!exit)
    {
        win->drawMenu(gameMenu, selected);
        int action = win->input();

        switch (action)
        {
        case Keys::UP:
        {
            if (selected > 0)
            {
                selected -= 1;
            }
            break;
        }
        case Keys::DOWN:
        {
            if (selected < gameMenu.size() - 1)
            {
                selected += 1;
            }
            break;
        }
        case Keys::ENTER:
        {
            if (gameMenu[selected] == "Play")
            {
                play(0);
            }
            else if (gameMenu[selected] == "Exit")
            {
                exit = true;
            }
            else if (gameMenu[selected] == "Levels")
            {
                options();
            }
        }
        }
    }
}

Loop::~Loop()
{
    delete win;
}

void Loop::options()
{
    const Menu gameLevels = {
        "Level 1",
        "Level 2",
        "Level 3",
        "Level 4",
        "Level 5",
        "Go Back",
    };
    int selectedLevel = 0;
    bool exit = false;
    while (!exit)
    {
        win->drawLevels(gameLevels, selectedLevel);
        int action = win->input();
        switch (action)
        {
        case Keys::UP:
        {
            if (selectedLevel > 0)
            {
                selectedLevel -= 1;
            }
            break;
        }
        case Keys::DOWN:
        {
            if (selectedLevel < gameLevels.size() - 1)
            {
                selectedLevel += 1;
            }
            break;
        }
        case Keys::ENTER:
        {
            if (gameLevels[selectedLevel] == "Go Back")
            {
                exit = true;
            }
            else
            {
                play(selectedLevel);
            }
        }
        }
    }
}