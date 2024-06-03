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
  Texture2D ekis(LoadTexture("C:/raylib/ekis.png"));
  ekis.height = 90;
  ekis.width = 90;
  Texture2D circ(LoadTexture("C:/raylib/circ.png"));
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
    grid[row][col] = elemento + 1;
  }
  Print();

}

/**
 * @brief 
 * 
 */
void Grid::DrawElement() {
  //if (!IsFull() && CombinacionGanadora() == 0) {
    for (int row = 0; row < numRows; row++)
    {
      for (int col = 0; col < numCols; col++)
      {
        if (grid[row][col] != 0) {
          if (grid[row][col] == 1) {
            DrawTexture(x, row * 100 + 5, col * 100 + 5, WHITE);
          } else if (grid[row][col] == 2) {
            DrawTexture(c, row * 100 + 5, col * 100 + 5, WHITE);
          }
        }
      }
    }
  //} else 
  if (CombinacionGanadora() == 1) {
    ClearBackground(WHITE);
    //DrawRectangle(0, 0, 300, 300, WHITE);
    DrawText("ganador ><", 20, 100, 50, WHITE);
    DrawText("presione click derecho\n para continuar", 10, 150, 20, WHITE);
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
      Initialize();
    }
  } else if (CombinacionGanadora() == 2) {
    ClearBackground(WHITE);
    //DrawRectangle(0, 0, 300, 300, WHITE);
    DrawText("ganador O", 20, 100, 50, WHITE);
    DrawText("presione click derecho\n para continuar", 10, 150, 20, WHITE);
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
      Initialize();
    }
  } else if (IsFull()) {
    Initialize();
  }
}

/**
 * @brief 
 * 
 * @return int 
 */
int Grid::CombinacionGanadora() {
//  if (IsFull()){
//    return false;
//  }
  int tempx{0}, tempc{0};
  
  // itera en cada fila
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      if (grid[row][col] == 1)
        tempx += grid[row][col];
      else if (grid[row][col] == 2)
        tempc += grid[row][col]; 
    }
    if (tempx == 3){
      return 1;
    } else if(tempc == 6) {
      return 2;
    }
    tempx = 0;
    tempc = 0;
  }

  // intera en cada columna
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      if (grid[col][row] == 1)
        tempx += grid[col][row];
      else if (grid[col][row] == 2)
        tempc += grid[col][row]; 
    }
    if (tempx == 3){
      return 1;
    } else if(tempc == 6) {
      return 2;
    }
    tempx = 0;
    tempc = 0;
  }

  //itera en diagonal principal
  for (int diago_princ = 0; diago_princ < numRows; diago_princ++)
  {
    if (grid[diago_princ][diago_princ] == 1)
        tempx += grid[diago_princ][diago_princ];
      else if (grid[diago_princ][diago_princ] == 2)
        tempc += grid[diago_princ][diago_princ]; 
  }
  if (tempx == 3){
    return 1;
  } else if(tempc == 6) {
    return 2;
  }
  tempx = 0;
  tempc = 0;
  
  //itera en diagonal secundaria
  for (int diago_secun = 0; diago_secun < numRows; diago_secun++)
  {
    //temp += grid[diago_secun][numCols - 1 - diago_secun];
    if (grid[diago_secun][numCols - 1 - diago_secun] == 1)
        tempx += grid[diago_secun][numCols - 1 - diago_secun];
      else if (grid[diago_secun][numCols - 1 - diago_secun] == 2)
        tempc += grid[diago_secun][numCols - 1 - diago_secun]; 
  }
  if (tempx == 3){
    return 1;
  } else if(tempc == 6) {
    return 2;
  }
  
  return 0;
}