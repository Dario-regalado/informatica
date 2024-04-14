/**
 * @file main_TTT.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "raylib.h"
#include "Grid.h"
#include "block.h"

int main() {
  InitWindow(300, 300, "raylib Tick Tack Toe");
  SetTargetFPS(30);
  Grid grid;
  grid.Print();
  Texture2D ekis(LoadTexture("TTT/ekis.png"));
  Texture2D circ(LoadTexture("TTT/circ.png"));

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    grid.Draw();
    for (int i = 0; i < 9; i++)
    {
      grid.CelPressed('x');
      grid.CelPressed('c');
    }
    
    EndDrawing();
  }
  CloseWindow();
}