#ifndef SNAKE_H
#define SNAKE_H

#include "general.h"
#include <vector>

class Snake_part {

private:
  // Data Members
  Line line;
  Column col;


public:
  // Constructor
  Snake_part( Line l, Column c ): line(l), col(c) {}

  // Member Functions
  // Getters
  Line get_line() const { return line; }
  Column get_column() const { return col; }

  // Setters
  void set_line( Line l) { line = l; }
  void set_column( Column c) { col = c; }


};

class Snake {

private:
  // Data Members
  Snake_part head;
  std::vector<Snake_part> tail;
  unsigned tail_size = 0;

public:
  // Constructor
  Snake( Line head_line, Column head_col ):
    head(head_line, head_col)
  {}

  // Member Functions
  // Getters
  Snake_part get_head() const { return head; }
  Snake_part get_tail_part( unsigned id ) const { return tail[id]; }
  unsigned get_tail_size() const { return tail_size; }

  // Setters
  void set_head( Line l, Column col );
  void set_tail( Line l, Column col, unsigned id );
  void increase_tail( Line l, Column col);


};


#endif
