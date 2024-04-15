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
  //SetTargetFPS(20);

  Grid grid;
  grid.Print();
  Block ex;
  Block ci;

  Texture2D ekis(LoadTexture("C:/Users/Equipo/Desktop/informatica/repositorio_mio/raylib/TTT/ekis.png"));

  Texture2D circ(LoadTexture("C:/Users/Equipo/Desktop/informatica/repositorio_mio/raylib/TTT/circ.png"));

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    grid.Draw();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      int x = GetMouseX();
      int y = GetMouseY();
      ex.SetParameters(x, y, ekis);
    }
      ex.Draw();
    
    
    EndDrawing();
  }
  CloseWindow();
}