#include "CursesWindow.h"



bool CursesWindow::term_has_colors() {

  return ( has_colors() and can_change_color() );
}



CursesWindow::CursesWindow( unsigned h, unsigned w, unsigned y0, unsigned x0 ):
  height(h), width(w)
{

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  
  win = newwin(h, w, y0, x0);

  keypad( win, TRUE );
}


void CursesWindow::destroy() {

  delwin(win);

}


/*void CursesWindow::print_borders(const char c, chtype attr ) {

  int input_box_y = (height * 4)/5;

  for( unsigned i=0; i<height; i++ )
    for( unsigned j=0; j<width; j++ ) {
      if( (i == 0) or (i == (height - 1)) )
        wprintw(win, "%d", i);
      else{

        if( (j == 0) or (j == (width - 1)) )  
          wprintw(win, "%d", j);
        else
          wprintw(win, " ");
      }

    }

  mvwhline(win, input_box_y, 1, 0, width - 2); 
  //wmove(win, input_box_y + (height/10), 1);
  wrefresh(win);

  //print_text(INPUT_TEXT, A_BOLD);
  
  print_text(input_box_y + (height/10), 1, INPUT_TEXT, A_BOLD);

}*/

void CursesWindow::reset_cursor() {

  int input_box_y = (height * 4)/5;
  std::string input_str = INPUT_TEXT;

  wmove(win, input_box_y + (height/10), input_str.length() + 1);
} 

void CursesWindow::display() {

  wbkgd(win, COLOR_PAIR(1));

  int input_box_y = (height * 4)/5;

  //box(win, 0, 0);
  mvwhline(win, input_box_y, 1, 0, width - 2);
  //wmove(win, input_box_y + (height/10), 1);

  print_text(input_box_y + (height/10), 1, INPUT_TEXT, A_BOLD);

}

void CursesWindow::print_borders() {

  wbkgd(win, COLOR_PAIR(1));

  int input_box_y = (height * 4)/5;

  box(win, 0, 0);
  mvwhline(win, input_box_y, 1, 0, width - 2);
  //wmove(win, input_box_y + (height/10), 1);

  print_text(input_box_y + (height/10), 1, INPUT_TEXT, A_BOLD);

}

void CursesWindow::print_text(int y0, int x0, const char *text, int attr) {

  wattron(win, attr);

  mvwprintw(win, y0, x0, text);
  wrefresh(win);

  wattroff(win, attr);

  reset_cursor();

}



int CursesWindow::get_game_input() {
    return wgetch( win );
}



void CursesWindow::get_input() {

  char buffer[BUFFER_SIZE] = {0};
  std::string tmp;

  while( tmp != "exit" ) {

    wgetnstr(win, buffer, BUFFER_SIZE);
    
    tmp = buffer;

    reset_cursor();

    for( unsigned i=0; i<tmp.length(); i++)
      waddch(win, ' ');

    reset_cursor();    

  }

}
