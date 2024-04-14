#pragma once
#include "position.h"
#include "raylib.h"

class Block {
 public:
  Block(int, int, Texture2D);
  Block();
  void Draw();
  void SetParameters(int, int, Texture2D);
  
 private:
  Position posicion;
  Texture2D texture;
};

