#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game():
  win( CURSES_LINES, CURSES_COLS, 0, 0), g( GRID_LINES, GRID_COLS ), sn( 0, 0 ) 
{

    
  init_color( COLOR_GREEN, 126, 200, 80 );

  init_pair(2, COLOR_WHITE, COLOR_GREEN);
  init_pair(3, COLOR_CYAN, COLOR_GREEN);
  init_pair(4, COLOR_RED, COLOR_RED);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);

  g.insert(0, 1, HEAD);
  g.insert(0, 0, TAIL);
  g.insert( GRID_LINES/2, GRID_COLS/2, 1 );

  sn.increase_tail(0, 0);

  win.set_input_timeout(700);
  win.display();

  print_game();



} 


Game::Game( unsigned curses_window_y0, unsigned curses_window_x0 ):
  win( CURSES_LINES, CURSES_COLS, curses_window_y0, curses_window_x0), g( GRID_LINES, GRID_COLS ), sn( 0, 0 ) 

{

    
  init_color( COLOR_GREEN, 126, 200, 80 );

  init_pair(2, COLOR_WHITE, COLOR_GREEN);
  init_pair(3, COLOR_CYAN, COLOR_GREEN);
  init_pair(4, COLOR_RED, COLOR_RED);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);

  g.insert(0, 1, HEAD);
  g.insert(0, 0, TAIL);
  g.insert( GRID_LINES/2, GRID_COLS/2, 1 );

  sn.increase_tail(0, 0);

  win.set_input_timeout(700);
  win.display();

  print_game();



}



void Game::print_game() {


  for( unsigned i=0; i < g.get_nlines(); i++ ) {
    for( unsigned j=0; j < g.get_ncolumns(); j++ ) {

      switch( g.get_square(i, j).get_content() ) {

        case EMPTY:
          win.print_text(i, j, ".", COLOR_PAIR(2));
        break;

        case FOOD:
          win.print_text(i, j, "*", COLOR_PAIR(3));
        break;

        case HEAD:
          win.print_text(i, j, "@", COLOR_PAIR(4));
        break;

        default:
          win.print_text(i, j, "x", COLOR_PAIR(5));

      }

    }

  }

}



void Game::set_direction() {

  switch( win.get_game_input() ) {

    case KEY_UP:
      snake_direction = UP;
    break;

    case KEY_DOWN:
      snake_direction = BOTTOM;
    break;

    case KEY_LEFT:
      snake_direction = LEFT;
    break;

    case KEY_RIGHT:
      snake_direction = RIGHT; 
    break;

    default:
      break;

    }

}

void Game::fix_tail_position( Line line, Column col) {

  Line tmp_line  = sn.get_tail_part(0).get_line();
  Column tmp_col = sn.get_tail_part(0).get_column();
 
  g.insert( tmp_line, tmp_col, EMPTY );
  g.insert( line, col, TAIL );
  sn.set_tail( line, col, 0 );



  for( unsigned i=1; i<sn.get_tail_size(); i++ ){

    Line l   = sn.get_tail_part(i).get_line();
    Column c = sn.get_tail_part(i).get_column();

     
    g.insert( l, c, EMPTY );
    g.insert( tmp_line, tmp_col, TAIL );
    sn.set_tail( tmp_line, tmp_col, i );

    tmp_line = l;
    tmp_col  = c;

  }


}

void Game::move_left() {


  Line line = sn.get_head().get_line();
  Column col = sn.get_head().get_column();

  bool is_food = g.get_square( line, col - 1U ).is_food();

  if( is_food )
    sn.increase_tail(0, 0), food_eaten = true;

  sn.set_head( line, col - 1U);
  g.insert( line, col - 1U, HEAD );
  g.insert( line, col, EMPTY );
  
  fix_tail_position(line, col);

}


void Game::move_right() {


  Line line = sn.get_head().get_line();
  Column col = sn.get_head().get_column();

  bool is_food = g.get_square( line, col + 1U ).is_food();

  if( is_food )
    sn.increase_tail(0, 0), food_eaten = true;

  sn.set_head( line, col + 1U);
  g.insert( line, col + 1U, HEAD );

  /*if( sn.get_tail_size() == 1 ) {

    g.insert( sn.get_tail_part(0).get_line(), sn.get_tail_part(0).get_column(), EMPTY );
    g.insert( line, col, TAIL );
    sn.set_tail( line, col, 0 );

  }
  else {

    

  }*/
  fix_tail_position(line, col);
  //g.insert( line, col, EMPTY );
  

}



void Game::move_up() {

  
  Line line = sn.get_head().get_line();
  Column col = sn.get_head().get_column();

  bool is_food = g.get_square( line - 1U, col ).is_food();

  if( is_food )
    sn.increase_tail(0, 0), food_eaten = true;

  sn.set_head( line - 1U, col );
  g.insert( line - 1U, col, HEAD );
  g.insert( line, col, EMPTY );

  fix_tail_position(line, col);

}



void Game::move_down() {


  Line line = sn.get_head().get_line();
  Column col = sn.get_head().get_column();

  bool is_food = g.get_square( line + 1U, col ).is_food();

  if( is_food )
    sn.increase_tail(0, 0), food_eaten = true;

  sn.set_head( line + 1U, col);
  g.insert( line + 1U, col, HEAD );
  g.insert( line, col, EMPTY );

  fix_tail_position(line, col);

}



void Game::move() {

  Line line = sn.get_head().get_line();
  Column col = sn.get_head().get_column();

  switch( get_snake_direction() ) {

    case LEFT:
      if( col == 0 )
        game_over = true;
      else if( ( sn.get_tail_part(0).get_line() == line ) and ( sn.get_tail_part(0).get_column() == col - 1 ) )
        set_direction( RIGHT );
      else if( g.get_square(line, col - 1).is_tail() )
        game_over = true;
      else
        move_left();
    break;

    case UP:
      if( line == 0 )
        game_over = true;
      else if( ( sn.get_tail_part(0).get_line() == line - 1 ) and ( sn.get_tail_part(0).get_column() == col ) )
        set_direction( BOTTOM );
      else if( g.get_square(line - 1, col).is_tail() )
        game_over = true;
      else
        move_up();
    break;

    case BOTTOM:
      if( line == g.get_nlines() - 1 )
        game_over = true;
      else if( ( sn.get_tail_part(0).get_line() == line + 1 ) and ( sn.get_tail_part(0).get_column() == col ) )
        set_direction( UP );
      else if( g.get_square(line + 1, col).is_tail() )
        game_over = true;
      else
        move_down();
    break;

    default:
      if( col == g.get_ncolumns() - 1 )
        game_over = true;
      else if( ( sn.get_tail_part(0).get_line() == line ) and ( sn.get_tail_part(0).get_column() == col + 1 ) )
        set_direction( LEFT );
      else if( g.get_square(line, col + 1).is_tail() )
        game_over = true;
      else
        move_right();

  }

  if( food_eaten ) {

    g.insert_food();
    food_eaten = false;

  }


}



void Game::play() {


  while( !game_over ) {

    move();
    set_direction();
    print_game();

    }

  win.destroy();

}
