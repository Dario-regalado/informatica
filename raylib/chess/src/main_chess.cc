/**
 * @file main_chess.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "raylib.h"
  //const Color dark{255, 255, 255, 255};

int main() {
  InitWindow(900, 900, "raylib chess");
  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
  }
  
  CloseWindow();
}