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
  Texture2D caballo (LoadTexture("C:/Users/Equipo/Desktop/informatica/1º de grado/Repositorio/raylib/apuestas/caballo.png"));
    caballo.width = 10;
    caballo.height = 10;
  desplazamiento_.resize(n);
  for (int i = 0; i < n; i++)
  {
    desplazamiento_[i] = 0;
  }
}

void Carrera::update() {
  int assert = rand() % n_caballos_ +1;
  for (int i = 0; i < n_caballos_; i++)
  {
    if (desplazamiento_[i] == assert){
      print(pixel_);
      desplazamiento_[i] += pixel_;
    }  
  }
}

void Carrera::print(int despl) {
  int height = height_screen_ - n_caballos_ * 10 - 10;
  for (int i = 0; i < n_caballos_; i++)
  {
    DrawTexture(caballo,despl,height,BLACK);
    height += pixel_;
  }
}

int Carrera::winer() {
  for (int i = 0; i < n_caballos_; i++) {
    if (desplazamiento_[i] == widht_screen_ - pixel_)
      return i + 1;
  }
  return 0;
}