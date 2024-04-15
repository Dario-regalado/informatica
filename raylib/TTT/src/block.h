#pragma once

#include <map>
#include "raylib.h"
#include "grid.h"

class Block {
 public:
  Block(Vector2, Texture2D);
  Block();
  void Draw();
  void SetParameters(Vector2, Texture2D);
  
  
 private:
  Vector2 posicion;
  Texture2D texture;
  void IsInside(Vector2);
};

