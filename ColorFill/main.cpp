#include <iostream>
#include <string>
#include "./Hero/Hero.hpp"
#include "./GamePlace/Place.hpp"
#include <ncurses.h>
#include "./Loop/Loop.hpp"

void startGame();

int  main() {
    initscr();
    keypad(stdscr, true);

    move(15, 45);
    printw("Press any key to start Game");
    int answer = getch();
    clear();

    if(answer) {
        startGame();
    }
    endwin();
    return 0;
}

void startGame() {
    Hero *Hero1 = new Hero();
    GamePlace *Place = new GamePlace();
    Loop NewGame(*Hero1, *Place);
    NewGame.menu();
}
