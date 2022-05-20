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

  if( CursesWindow::term_has_colors() ) {

    Game game;
    game.play();

  }
  else    
    std::cerr << "Your terminal does not support curses colors !" << std::endl;

  endwin();
 
  return 0;

}
