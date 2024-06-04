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
#include "chess.h"

int widht = 800;
int height = 800;
int x = -100;
int y = -100;
bool presionado = false;

int main() {
  InitWindow(widht, height, "raylib chess");
  SetTargetFPS(60);
  Chess juego;
  Vector2 pos;
  int x = -100;
  int y = -100;
  bool presionado = false;

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);

    juego.griddraw();
    juego.drawpieces();
    juego.drawpositions(x, y);
    if(!presionado && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      pos = GetMousePosition();
      x = int(pos.x);
      y = int(pos.y);
      presionado = true;
    } else if (presionado && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
      pos = GetMousePosition();
      juego.update1(x, y, pos.x, pos.y);
      x = -100;
      y = -100;
      presionado = false;
    }
    //juego.print();


    EndDrawing();
  }
  
  CloseWindow();
}