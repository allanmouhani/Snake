#include "Square.h"

void Square::set_content( Content c ) {

  if( (c == EMPTY) or (c == HEAD) or (c == TAIL) or (c == FOOD) )
    content = c;

  // Add exception handling in else, in case c is not EMPTY, HEAD, TAIL or FOOD ? 

}

