#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ncurses.h>

#include "Square.h"
#include "Grid.h"
#include "Snake.h"
#include "Game.h"
#include "CursesWindow.h"
#include "general.h"

int main() {

  initscr();
  cbreak();
  noecho();

  box(stdscr, 0, 0);

  unsigned x, y;
  getmaxyx(stdscr, y, x);

  y = (y / 2) - (CURSES_LINES / 2);
  x = (x / 2) - (CURSES_COLS / 2);

  if( CursesWindow::term_has_colors() ) {

    Game game(y,x);
    game.play();

  }
  else    
    std::cerr << "Your terminal does not support curses colors !" << std::endl;

  endwin();
 
  return 0;

}
