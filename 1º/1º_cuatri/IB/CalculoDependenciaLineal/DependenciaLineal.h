/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 18 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#pragma once
#include <vector>
#include <array>

class DepdendenciaLineal {
 public:
  DepdendenciaLineal(std::vector<std::vector<int>> base) : base_{base} {}

 private:
  std::vector<std::vector<int>> base_{};
};