/**
 * @file main.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "raylib.h"
#include "snake.h"

int main() {
  int width{600};
  int height{600};
  InitWindow(width, height, "raylib snake");
  SetTargetFPS(60);

  //Vector2 pos;
  Snake snake;

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    snake.DrawBackground();   
    
    
    
    EndDrawing();
  }
  CloseWindow();
}