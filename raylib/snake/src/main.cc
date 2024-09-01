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
  SetTargetFPS(10);

  //Vector2 pos;
  Snake snake;
  Direction direccion = north;

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    snake.DrawBackground();   
    snake.DrawSnake();
    if(snake.GetInGame()){
      if(IsKeyPressed(KEY_UP) && direccion != south) 
      direccion = north;
      else if(IsKeyPressed(KEY_DOWN) && direccion != north) 
        direccion = south;
      else if(IsKeyPressed(KEY_LEFT) && direccion != east) 
        direccion = west;
      else if(IsKeyPressed(KEY_RIGHT) && direccion != west) 
        direccion = east;
      
      snake.Update(direccion);

    }
    EndDrawing();
  }
  CloseWindow();
}