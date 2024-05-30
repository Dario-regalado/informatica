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
#include "Point2D.h"

class Circle {
 public:
  Circle() = default;
  int GetRadio() const {return radio_;}
  Point2D GetCenter() const {return punto_;}
 private:
  int radio_;
  Point2D punto_;
};

