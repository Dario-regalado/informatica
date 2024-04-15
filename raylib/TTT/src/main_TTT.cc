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

  Grid grid;
  grid.Print();
  Block ex;
  Block ci;

  Texture2D ekis(LoadTexture("C:/Users/Equipo/Desktop/informatica/repositorio_mio/raylib/TTT/ekis.png"));
  ekis.height = 90;
  ekis.width = 90;
  Texture2D circ(LoadTexture("C:/Users/Equipo/Desktop/informatica/repositorio_mio/raylib/TTT/circ.png"));
  circ.height = 90;
  circ.width = 90;

  Vector2 pos;
  

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    grid.Draw();
    
    for (int i = 0; i < 9; i++){
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        pos = GetMousePosition();
        ci.SetParameters(pos, circ);
        ci.Draw();
      }    
    }
    EndDrawing();
  }
  CloseWindow();
}