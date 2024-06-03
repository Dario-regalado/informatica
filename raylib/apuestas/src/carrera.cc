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

#include "carrera.h"

Carrera::Carrera(int we, int hi, int n) {
  widht_screen_ = we;
  height_screen_ = hi;
  pixel_ = we / 10;
  n_caballos_ = n;
  Texture2D caballo(LoadTexture("C:/raylib/caballo.png"));
    caballo.width = pixel_;
    caballo.height = pixel_;
  caballo_ = caballo;
  desplazamiento_.resize(n);
  for (int i = 0; i < n; i++){
    desplazamiento_[i] = 0;
  }
}

void Carrera::update() {
  int assert = rand() % (n_caballos_); // Elegir el caballo que avanza, número entre 1 y número de caballos
  // Crear un buffer para el mensaje
  char mensaje[3]; // Asumiendo que n_caballos_ nunca será más de 99
  // Convertir el número a una cadena y almacenarlo en el buffer
  sprintf(mensaje, "%d", assert);

  for (int i = 0; i < n_caballos_; i++)
  {
    if (i == assert){
      //print();
      //DrawText(mensaje, 0,0, 30, WHITE);
      desplazamiento_[i] += pixel_ / 4;
    }  
  }
}

/*
void Carrera::print() {
  int height = height_screen_ - (n_caballos_ * pixel_);
  for (int i = 0; i < n_caballos_; i++) {
    // Asegúrate de que la textura caballo_ esté cargada correctamente
    if (caballo_.id > 0) {
      // Dibuja la textura con las dimensiones correctas
      Rectangle sourceRec = { 0.0f, 0.0f, (float)caballo_.width, (float)caballo_.height };
      Rectangle destRec = { (float)desplazamiento_[i], (float)height, (float)caballo_.width * 10, (float)caballo_.height * 10 };
      Vector2 origin = { (float)caballo_.width / 2, (float)caballo_.height / 2 };
      DrawTexturePro(caballo_, sourceRec, destRec, origin, 0.0f, WHITE);
    }
    height += pixel_;
  }
}
*/


void Carrera::print() {
  int height = height_screen_ - (n_caballos_ * pixel_);
  for (int i = 0; i < n_caballos_; i++)
  {
    //DrawRectangle(desplazamiento_[i], height, pixel_, pixel_, WHITE);
    DrawTexture(caballo_,desplazamiento_[i],height,WHITE);
    height += pixel_;
  }
}

int Carrera::winer() {
  for (int i = 0; i < n_caballos_; i++) {
    if (desplazamiento_[i] >= widht_screen_ - pixel_)
      return i + 1;
  }
  return 0;
}

void Carrera::reinitialize() {
  for (int i = 0; i < n_caballos_; i++)
    desplazamiento_[i] = 0; 
}