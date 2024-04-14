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
#include "raylib.h"

class Grid {
 public:  
  Grid();
  void Initialize();
  bool grid[3][3];
  void Draw();
  void Print();
  void CelPressed(char);

 private:
  int numRows;
  int numCols;
  int celSize;

};