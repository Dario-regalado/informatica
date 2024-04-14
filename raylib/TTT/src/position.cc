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

/**
 * @brief Construct a new Position:: Position object
 * 
 * @param row 
 * @param column 
 */
Position::Position(int row, int column) {
  this->row = row;
  this->column = column;
}

/**
 * @brief Construct a new Position:: Position object
 * 
 */
Position::Position(){}

/**
 * @brief 
 * 
 * @param r 
 * @param c 
 */
void Position::SetPosition(int r, int c) {
  row = r;
  column = c;
}