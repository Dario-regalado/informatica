/**
 * @file snake.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "snake.h"

Snake::Snake() {
  nrow_ = 20;
  ncol_ = 20;
  cellsize_ = 600 / nrow_;
  for (int i = 0; i < nrow_; i++) {
    for (int j = 0; j < ncol_; j++)
    {
      grid[i][j] = 0;
    }
  }

}

void Snake::DrawBackground(){
  for (int i = 0; i < GetNrow(); i++) {
    for (int j = 0; j < GetNcol(); j++) {
      if ((i + j)%2 == 0)
        DrawRectangle(i * GetCellsize()+1, j * GetCellsize()+1, GetCellsize()-1, GetCellsize()-1, GREEN);
      else
        DrawRectangle(i * GetCellsize()+1, j * GetCellsize()+1, GetCellsize()-1, GetCellsize()-1, LIGHTGRAY);
    }
  }
}

