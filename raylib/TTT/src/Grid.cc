#include <iostream>
#include "Grid.h"


/**
 * @brief Construct a new Grid:: Grid object
 * 
 */
Grid::Grid() {
  numRows = 3;
  numCols = 3;
  celSize = 100;
  Initialize();

}

/**
 * @brief 
 * 
 */
void Grid::Initialize() {
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      grid[row][col] = 0;
    }
  }
}

/**
 * @brief 
 * 
 */
void Grid::Draw() {
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      DrawRectangle(row * celSize+1, col*celSize+1, celSize-1, celSize-1, BLUE);
    } 
  } 
}

/**
 * @brief 
 * 
 */
void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std::cout << 0 << " ";
    }
    std::cout << std::endl;
  }
}

bool Grid::IsFull() {
  int casillas_lennas{0};
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++){
      if(grid[row][col] != 0)
        casillas_lennas++;
    }
  }
  return casillas_lennas == 9;
}