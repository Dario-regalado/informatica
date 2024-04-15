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
  while(!WindowShouldClose()) {
    BeginDrawing();
    //DrawText("click to set you option", 10, 10, 20, DARKGRAY);
    IsInside(posicion);
    DrawTexture(texture, posicion.x + 5, posicion.y + 5, WHITE);
    EndDrawing();
  }  
}

/**
 * @brief 
 * 
 * @param row 
 * @param col 
 * @param image 
 */
void Block::SetParameters(Vector2 pos, Texture2D image) {
  texture = image;
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