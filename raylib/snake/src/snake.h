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
#include "dll_t.h"
#include "raylib.h"

struct Pair {
  int row, col;
  Pair(int r, int c) {row = r; col = c;}
  Pair() = default;
};
inline bool operator==(Pair p, Pair s) {return p.row == s.row && p.col == s.col;}

enum Direction {
  north,
  south,
  east,
  west,
};

class Snake {
 public:
  Snake();
  bool grid[30][30];
  void Update(Direction);

  // draw elements
  void DrawBackground();
  void DrawSnake();

  //getters
  int GetNrow(void) const {return nrow_;}
  int GetNcol(void) const {return ncol_;}
  int GetCellsize(void) const {return cellsize_;}
  bool GetInGame(void) const {return ingame_;}

 private:
  int ncol_;
  int nrow_;
  int cellsize_;
  bool ingame_;
  dll_t<Pair> pos;
};