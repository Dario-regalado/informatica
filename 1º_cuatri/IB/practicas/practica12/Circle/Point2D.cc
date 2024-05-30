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

#include "Point2D.h"

std::istream& operator>>(std::istream& is, Point2D& punto_nuevo) {
  is >> punto_nuevo.x_ >> punto_nuevo.y_;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Point2D& punto_nuevo) {
  os << punto_nuevo.GetX() << " " << punto_nuevo.GetY();
  return os;
}