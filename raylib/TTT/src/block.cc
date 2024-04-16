/**
 * @file block.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include "block.h"

/**
 * @brief Construct a new Block:: Block object
 * 
 * @param row 
 * @param col 
 * @param image 
 */

Block::Block(Vector2 pos, Texture2D image) {
  texture = image;
  posicion = pos;
}


Block::Block(Texture2D image) {
  texture = image;
}


/**
 * @brief Construct a new Block:: Block object
 * 
 */
Block::Block() {}

/**
 * @brief 
 * 
 */
void Block::Draw() {
    //DrawText("click to set you option", 10, 10, 20, DARKGRAY);
    IsInside(posicion);
    // std::cout << posicion.x << " " << posicion.y << std::endl;
    DrawTexture(texture, 0, 0, WHITE);
}

/**
 * @brief 
 * 
 * @param pos 
 * @param image 
 */
void Block::SetParameters(Vector2 pos, Texture2D image) {
  texture = image;
  posicion = pos;
}


void Block::SetParameters(Vector2 pos) {
  posicion = pos;
}

/**
 * @brief 
 * 
 * @param pos 
 */
void Block::IsInside(Vector2 pos) {
  posicion.x = int(pos.x / 100);
  posicion.y = int(pos.y / 100);
}