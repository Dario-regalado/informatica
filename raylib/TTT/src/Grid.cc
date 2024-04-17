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

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
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

/**
 * @brief 
 * 
 * @param row 
 * @param col 
 * @param elemento 
 */
void Grid::Update(int row, int col, int elemento) {
  if (grid[row][col] == 0) {
    grid[row][col] = elemento;
  }
  Print();

}

/**
 * @brief 
 * 
 */
void Grid::DrawElement() {
  if (!IsFull() && !CombinacionGanadora()) {
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
  } else if (CombinacionGanadora()) {
    ClearBackground(WHITE);
    DrawRectangle(0, 0, 300, 300, WHITE);
    DrawText("ganador", 50, 100, 50, BLACK);
  } else {
    //reiniciar el juego
  }
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Grid::CombinacionGanadora() {
//  if (IsFull()){
//    return false;
//  }
  int temp{0};
  
  // itera en cada fila
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      temp += grid[row][col];
    }
    if (temp == 3 || temp == 6){
      return true;
    }
    temp = 0;
  }

  // intera en cada columna
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      temp += grid[col][row];
    }
    if (temp == 3 || temp == 6){
      return true;
    }
    temp = 0;
  }

  //itera en diagonal principal
  for (int diago_princ = 0; diago_princ < numRows; diago_princ++)
  {
    temp += grid[diago_princ][diago_princ];
  }
  if (temp == 3 || temp == 6) {
    return true;
  }
  temp = 0;
  
  //itera en diagonal secundaria
  for (int diago_secun = 0; diago_secun < numRows; diago_secun++)
  {
    temp += grid[diago_secun][numCols - 1 - diago_secun];
  }
  if (temp == 3 || temp == 6) {
    return true;
  }
  
  return false;
}