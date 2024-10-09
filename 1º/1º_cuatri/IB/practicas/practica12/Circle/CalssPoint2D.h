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
#include <iostream>
#include <cmath>

class Point2D {
 public:
  Point2D (double coordenada_x, double coordenada_y) : x_{coordenada_x}, y_{coordenada_y} {};
  Point2D() {};
  double GetX() const {return x_;}
  double GetY() const {return y_;}
  void Show ();
  void Move (const double &move_x, const double &move_y);
  double Distance (const Point2D& point1);
  Point2D Middle(const Point2D& point1);
 private:
  double x_;
  double y_;
};