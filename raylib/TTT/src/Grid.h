/**
 * @file main_TTT.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include "raylib.h"
#include "block.h"

class Grid {
 public:  
  Grid();
  void Initialize();
  int grid[3][3];
  void Draw();
  void Print();

 private:
  int numRows;
  int numCols;
  int celSize;

};