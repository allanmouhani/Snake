#ifndef GENERAL_H
#define GENERAL_H

#define EMPTY 0
#define FOOD 1
#define HEAD 2
#define TAIL 3

// 24 because CURSES_LINES real size is 24: (30*4)/5
#define GRID_LINES 24 
#define GRID_COLS 64

#define CURSES_LINES 30
#define CURSES_COLS 64


#define LEFT 0
#define RIGHT 1
#define UP 2
#define BOTTOM 3

using Direction = unsigned;

using Line    = unsigned;
using Column  = unsigned;
using Content = unsigned;

#endif
