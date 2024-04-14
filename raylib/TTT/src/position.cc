/**
 * @file position.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "position.h"

Position::Position(int row, int column) {
  this->row = row;
  this->column = column;
}

void Position::SetPosition(int r, int c) {
  row = r;
  column = c;
}