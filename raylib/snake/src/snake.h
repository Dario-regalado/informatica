/**
 * @file snake.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include "raylib.h"

class Snake {
 public:
  Snake();
  int grid[20][20];
  void DrawBackground();

  //getters
  int GetNrow(void) const {return nrow_;}
  int GetNcol(void) const {return ncol_;}
  int GetCellsize(void) const {return cellsize_;}

 private:
  int ncol_;
  int nrow_;
  int cellsize_;
};