/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 03 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#pragma once
#include <cmath>
#include <iostream>
#include "CalssPoint2D.h"

enum Color {
  amarillo,
  naranja,
  rojo,
  verde,
  azul,
  morado,
  violeta,
  rosa,
  negro,
  blanco,
};

class Cirlce {
 public:
  Cirlce(const Point2D& centro, double radio, Color color) : centro_{centro}, radio_{radio}, color_{color} {}
  Cirlce() {};
  double Area();
  double Preimetro();
  void Print();
  void EsInterior(const Point2D &punto_a_comprobar);

 private:
  Point2D centro_{};
  double radio_{};
  Color color_{};
};

