#ifndef SQUARE_H
#define SQUARE_H

#include "general.h"


class Square {

private:
  // Data Members
  Line line = 0;
  Column col = 0;
  Content content = EMPTY;


public:
  // Constructor
  Square() = default;
  Square( Line l, Column col, Content c): line(l), col(col), content(c) {}

  // Member Functions
  // Getters
  Line get_line() const { return line; }
  Column get_column() const { return col; }
  Content get_content() const { return content; }
  bool is_empty() const { return (content == EMPTY); }
  bool is_food() const { return (content == FOOD); }
  bool is_tail() const { return (content == TAIL); }


  // Setters
  void set_content( Content c );
  void set_line( Line l ) { line = l; }
  void set_column( Column c ) { col = c; }



}; 


#endif
