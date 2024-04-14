/**
 * @file grid.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */


class Grid {
 public:
  Grid();
  bool grid [8][8];
  void Initialize();
  void Print();

 private:
  int numRows;
  int numCols;
  int cellSize;
};