#pragma once
#include "position.h"
#include "raylib.h"

class Block {
 public:
  Block(int, int, char);
  Block();
  void Draw();
  void SetParameters(int row, int col, char b);
 private:
  Image image;
  Position posicion;
  Texture2D texture;
};

