/**
 * @file carrera.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string.h>
#include "raylib.h"
#include "carrera.h"

int heigth = 600;
int width = 600;
#define MAX_INPUT_CHARS     9

bool IsAnyKeyPressed();
string caja();
bool apuesta = false;



int main () {
  InitWindow(width, heigth, "Apuestas ilegales");
  SetTargetFPS(20);
  Carrera carrera1(width, heigth, 6);
  string cantidad;

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLUE);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      apuesta = true;

    if(apuesta == true) {
      if(carrera1.winer() == 0) {
        carrera1.print();
        carrera1.update();
      } else {
        //ClearBackground(BLACK);
        carrera1.print();
        int numeroGanador = carrera1.winer();
        // Crear una cadena base para el mensaje
        const char* base = "el ganador es el caballo: ";
        // Calcular la longitud total del mensaje (longitud de la base + dígitos del número + 1 para el carácter nulo)
        int longitudTotal = strlen(base) + snprintf(NULL, 0, "%d", numeroGanador) + 1;
        // Crear un buffer para el mensaje final
        char* ganador = new char[longitudTotal];
        // Construir el mensaje final
        sprintf(ganador, "%s%d", base, numeroGanador);
        // Dibujar el mensaje en la pantalla
        DrawText(ganador, width / 3 , heigth / 4 - 10, 15, WHITE);
        // No olvides liberar la memoria después de usarla
        delete[] ganador;
        DrawText("click derecho para reiniciar", width / 4,heigth / 2, 20, WHITE);

        // reiniciar al carrera carrera1
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
          carrera1.reinitialize();
      }
    } else{
      DrawText("click izquierdo para empezar", width / 4,heigth / 2, 20, WHITE);
    }
    
    EndDrawing();
  }
  CloseWindow();
}

string caja() {
  char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;

    Rectangle textBox = { width/2.0f - 100, 180, 225, 50 };
    bool mouseOnText = false;

    int framesCounter = 0;

    SetTargetFPS(10);               // Set our game to run at 10 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    name[letterCount+1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key = GetCharPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);

            DrawRectangleRec(textBox, LIGHTGRAY);
            if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
            else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

            DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

            DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);

            if (mouseOnText)
            {
                if (letterCount < MAX_INPUT_CHARS)
                {
                    // Draw blinking underscore char
                    if (((framesCounter/20)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
                }
                else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


// Check if any key is pressed
// NOTE: We limit keys check to keys between 32 (KEY_SPACE) and 126
  string apuesta = static_cast<string>(name);
  return apuesta;
}
bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}