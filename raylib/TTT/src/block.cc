#include "block.h"

/**
 * @brief Construct a new Block:: Block object
 * 
 * @param row 
 * @param col 
 * @param image 
 */
Block::Block(int row, int col, Texture2D image) {
  texture = image;
  posicion.SetPosition(row, col);
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
  BeginDrawing();
  ClearBackground(BLUE);
  DrawText("click to set you option", 10, 10, 20, DARKGRAY);
  DrawTexture(texture, posicion.GetRow()*100, posicion.GetCol()*100, WHITE);
  EndDrawing();
}

/**
 * @brief 
 * 
 * @param row 
 * @param col 
 * @param image 
 */
void Block::SetParameters(int row, int col, Texture2D image) {
  texture = image;
  posicion.SetPosition(row, col);
}