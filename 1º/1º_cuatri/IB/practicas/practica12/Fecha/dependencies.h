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

class Fecha {
 public:
  Fecha (int d, int m, int y) : day_{d}, month_{m}, year_{y} {
    if (is_valid_date(d, m, y) == 0) {
      std::cerr << "Error, la fecha es invalida" << std::endl;
    }
  }
  void AnoBisiesto();
 private:
  bool is_valid_date(int d, int m, int y);
  int day_{};
  int month_{};
  int year_{};
};