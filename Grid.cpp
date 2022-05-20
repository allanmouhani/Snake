#include <iostream>
#include <cstdlib>
#include "Grid.h"

Grid::Grid( unsigned l, unsigned c ):
  lines(l), cols(c) 
{
  for( unsigned i=0; i<lines; i++)
    for( unsigned j=0; j<cols; j++) {

      grid[i][j].set_line(i);
      grid[i][j].set_column(j);
      grid[i][j].set_content(EMPTY);

    }


}


void Grid::insert( unsigned l, unsigned c, Content cont ) {

  if( (l < lines) and (c < cols) )
    grid[l][c].set_content(cont); 

  // Add exception handling in else, in case line >= lines or col >= cols 

}


void Grid::insert_food() {

  srand(time(nullptr));

  Line l = 0;
  Column col = 0; 

  do {
    l = rand() % lines;
    col = rand() % cols;

  }while( not get_square(l, col).is_empty() );

  insert(l, col, FOOD);

}

/*void print_grid( const Grid &g ) {

  unsigned nlines = g.get_nlines(), ncols = g.get_ncolumns();

  for( unsigned i=0; i<nlines; i++ ) {
    for( unsigned j=0; j<ncols; j++ ) {
      if( g.get_square(i, j).get_content() == EMPTY ) {
        std::cout << " ";
        continue;
      }

      std::cout << g.get_square(i, j).get_content() << " ";

    }

    std::cout << std::endl;

  }

}*/
