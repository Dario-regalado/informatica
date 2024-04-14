/**
 * @file position.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

class Position {
 public:
  Position(int, int);
  Position();
  int GetRow() const {return row;}
  int GetCol() const {return column;}
  void SetPosition(int, int);
 private:
  int row;
  int column;
};
