#ifndef NCURSES_WINDOW_H
#define NCURSES_WINDOW_H

#include <ncurses.h>
#include <string>

#define BUFFER_SIZE 128
#define INPUT_TEXT "Enter your input here:  "

class CursesWindow {

private:
  // Data Members
  WINDOW *win = nullptr;
  unsigned height;
  unsigned width;

  void reset_cursor();


public:
  // Constructor
  CursesWindow( unsigned h, unsigned w, unsigned y0, unsigned x0 );

  // Interface
  static bool term_has_colors(); 
  void destroy();
  void print_borders();
  void display();
  void print_borders(const char c, chtype attr );
  void print_text(int y0, int x0, const char *text, int attr=A_NORMAL);
  void get_input();
  int get_game_input();
  void set_input_timeout( int tenths ) { wtimeout( win, tenths );  };

};
 

#endif
