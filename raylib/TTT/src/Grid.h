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

class Grid {
 public:  
  Grid();
  void Initialize();
  int grid[3][3];
  void Print();
  void GridDraw();
  void DrawElement();
  bool IsFull();
  void Update(int, int, int);
  int CombinacionGanadora();

private:
  int numRows;
  int numCols;
  int celSize;
  Texture2D x, c;
};