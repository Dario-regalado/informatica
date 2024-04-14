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
#pragma once
#include <iostream>
#include <raylib.h>

int main() {
  Color dark = {255, 255, 255, 255};
  InitWindow(300, 300, "raylib chess");
  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(dark);

    EndDrawing();
  }
  
  CloseWindow();
}