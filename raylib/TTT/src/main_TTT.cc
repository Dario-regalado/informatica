/**
 * @file main_TTT.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 *  https://www.youtube.com/watch?v=wVYKG_ch4yM&list=PLwR6ZGPvjVOSRywn9VCQ3yrRVruxzzuo9
 */

#include <iostream>
#include "raylib.h"
#include "Grid.h"


int main() {
  InitWindow(300, 300, "raylib Tick Tack Toe");
  SetTargetFPS(60);

  int symbol{0};
  Vector2 pos;
  Grid grid;
  // grid.Print();

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    grid.GridDraw();
    grid.DrawElement();
    
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      pos = GetMousePosition();
      int x = int(pos.x / 100);
      int y = int(pos.y / 100); 
      // std::cout << pos.x << " " << pos.y << std::endl;
      grid.Update(x, y, symbol % 2);
      symbol++;
    }
    
    EndDrawing();
  }
  CloseWindow();
}