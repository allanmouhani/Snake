#ifndef GAME_H
#define GAME_H

#include "general.h"
#include "Grid.h"
#include "Snake.h"
#include "CursesWindow.h"


class Game {

private:
  // Data Members
  CursesWindow win;
  Grid g;
  Snake sn;
  Direction snake_direction = RIGHT;
  bool food_eaten = false;
  bool game_over = false;

  // Member Functions
  void print_game();
  void set_direction();
  void set_direction( Direction dir ) { snake_direction = dir; }
  void move_left();
  void move_right();
  void move_up();
  void move_down();
  void move();
  Direction get_snake_direction() const { return snake_direction; }
  void fix_tail_position( Line line, Column col);

public:
  Game();
  void play();


};


#endif
