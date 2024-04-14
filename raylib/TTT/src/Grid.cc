#include <iostream>
#include "Grid.h"
#include "block.h"


Grid::Grid() {
  numRows = 3;
  numCols = 3;
  celSize = 100;
  Initialize();

}

void Grid::Initialize() {
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      grid[row][col] = 0;
    }
  }
}

void Grid::Draw() {
  for (int row = 0; row < numRows; row++)
  {
    for (int col = 0; col < numCols; col++)
    {
      DrawRectangle(row * celSize+1, col*celSize+1, celSize-1, celSize-1, BLACK);
    } 
  } 
}


void Grid::CelPressed(char b) {
  if (IsMouseButtonPressed(1)) {
    int x = GetMouseX();
    int y = GetMouseY();
    grid[x][y] = 1;
    Block bloq;
    if (b == 'x') {
      bloq.SetParameters(x, y, b);
    } else {
      bloq.SetParameters(x, y, b);
    }
  }
}

void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std::cout << (grid[row][col] == 0 ? "0" : "1") << " ";
    }
    std::cout << std::endl;
  }
}