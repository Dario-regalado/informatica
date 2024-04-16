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

#include <iostream>
#include "raylib.h"
#include "Grid.h"

/*
double lastUpdatetime = 0;

bool EvenTriggered(double interval){
  double currentTime = GetTime();
  if(currentTime - lastUpdatetime >= interval) {
    lastUpdatetime = currentTime;
    return true;
  }
  return false;
}
*/

int main() {
  InitWindow(300, 300, "raylib Tick Tack Toe");
  SetTargetFPS(60);

  Vector2 pos;
  Grid grid;
  grid.Print();

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    grid.GridDraw();
    grid.DrawElement();
    
    if(!grid.IsFull() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      pos = GetMousePosition();
      pos.x = int(pos.x / 100);
      pos.y = int(pos.y / 100); 
      // std::cout << pos.x << " " << pos.y << std::endl;
      grid.Update(pos.x, pos.y, 1);
    }
    EndDrawing();
  }
  CloseWindow();
}