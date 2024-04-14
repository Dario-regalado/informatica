/**
 * @file grid.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include "Grid.h"

Grid::Grid () {
  numRows = 8;
  numCols = 8;
  cellSize = 60;
}

void Grid::Initialize() {
  
  for (int row = 0; row < 2; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      grid[row][col] = 1;
    }
  }
  for (int row = 0; 2 <= row && row <= numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      grid[row][col] = 0;
    }
  }
  for (int row = numRows; row > numRows-2 ; row--)
  {
    for (int col = 0; col < numCols; col++)
    {
      grid[row][col] = 1;
    }
  } 
}

void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std::cout << "|";
    }
    std::cout << std::endl;
  }
}