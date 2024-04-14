#include "block.h"

Block::Block(int row, int col, char b) {
  if (b == 'x')
    image = LoadImage("resources/ekis.png");
  else
    image = LoadImage("resources/circ.png");
  texture = (LoadTextureFromImage(image));
  posicion.SetPosition(row, col);
  Draw();
}

void Block::Draw() {
  DrawTexture(texture, posicion.GetRow()*100, posicion.GetCol()*100, BLACK);
}

void Block::SetParameters(int row, int col, char b) {
  if (b == 'x')
    image = LoadImage("resources/ekis.png");
  else
    image = LoadImage("resources/circ.png");
  texture = (LoadTextureFromImage(image));
  posicion.SetPosition(row, col);
  Draw();
}