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
  Texture2D ekis(LoadTexture("C:/Users/Equipo/Desktop/informatica/repositorio_mio/raylib/TTT/ekis.png"));
  ekis.height = 90;
  ekis.width = 90;
  Texture2D circ(LoadTexture("C:/Users/Equipo/Desktop/informatica/repositorio_mio/raylib/TTT/circ.png"));
  circ.height = 90;
  circ.width = 90;
  x = ekis;
  c = circ;
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
void Grid::GridDraw() {
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
      std::cout << grid[col][row] << " ";
    }
    std::cout << std::endl;
  }
}

bool Grid::IsFull() {
  int casillas_llenas{0};
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++){
      if(grid[row][col] != 0) {
        casillas_llenas++;
      }
    }
  }
  return casillas_llenas == 9;
}


void Grid::Update(int row, int col, int elemento) {
  if (grid[row][col] == 0) {
    grid[row][col] = elemento;
  }
  Print();

}

void Grid::DrawElement() {
  if (!IsFull()) {
    for (int row = 0; row < numRows; row++)
    {
      for (int col = 0; col < numCols; col++)
      {
        if (grid[row][col] != 0) {
          if (grid[row][col] == 1) {
            DrawTexture(x, row * 100 + 5, col * 100 + 5, WHITE);
          } else if (grid[row][col] == 2) {
            DrawTexture(c, row + 5, col + 5, WHITE);
          }
        }
      }
      
    }
    
  }
}