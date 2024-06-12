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
#include "CalssPoint2D.h"
#pragma once

void Point2D::Show () {
  std::cout << "coordenada x = " << x_ << std::endl;
  std::cout << "coordenada y = " << y_ << std::endl;
}
void Point2D::Move (const double &move_x, const double &move_y) {
  x_ += move_x;
  y_ += move_y;
}
double Point2D::Distance (const Point2D& point1) {
  return sqrt((point1.GetX() - x_) + (point1.GetY() - y_));
}
Point2D Point2D::Middle(const Point2D& point1) {
  double coordenada_x{((point1.GetX() + x_) / 2)};
  double coordenada_y{((point1.GetY() + y_) / 2)};
  Point2D return_point{coordenada_x, coordenada_y};
  return return_point;
}
