#include "Snake.h"


void Snake::set_head( Line l, Column col ) {

  head.set_line(l);
  head.set_column(col);

}

void Snake::set_tail( Line l, Column col, unsigned id ) {

  if( id >= tail.size() )
    return; // throw some error
  else {

    tail[id].set_line(l);
    tail[id].set_column(col);

  }

}


void Snake::increase_tail( Line l, Column col) {

  tail.push_back( Snake_part(l, col) );
  ++tail_size;

}
