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
      DrawRectangle(row * celSize+1, col*celSize+1, celSize-1, celSize-1, BLACK);
    } 
  } 
}


/**
 * @brief 
 * 
 * @param image 
 */
void Grid::CelPressed(Texture2D image) {
  if (IsMouseButtonPressed(1)) {
    int x = GetMouseX();
    int y = GetMouseY();
    grid[x][y] = 1;
    Block bloq;
    bloq.SetParameters(x, y, image);
    bloq.Draw();
    }
  }

/**
 * @brief 
 * 
 */
void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std::cout << (grid[row][col] == 0 ? "0" : "1") << " ";
    }
    std::cout << std::endl;
  }
}