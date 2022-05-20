#ifndef GRID_H
#define GRID_H

#include "Square.h"
#include "general.h"

class Grid {

private:
  // Data Members
  const unsigned lines;
  const unsigned cols;

  Square grid[GRID_LINES][GRID_COLS];


public:
  // Constructor
  Grid( unsigned l, unsigned c );

  // Member Functions
  unsigned get_nlines() const { return lines; }
  unsigned get_ncolumns() const { return cols; }
  void insert( unsigned l, unsigned c, Content cont );
  void insert_food();
  Square get_square( unsigned l, unsigned c ) const { return grid[l][c]; }   

};

void print_grid( const Grid &g );


#endif
