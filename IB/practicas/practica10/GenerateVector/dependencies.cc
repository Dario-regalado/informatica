/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 20 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "dependencies.h"

std::vector<double> GenerateVector(const int size, const double lower, const double upper){
  std::vector<double> return_vector{};
  // return_vector.size() = size;
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<> distr(lower, upper);
  for (int i{0}; i < size; ++i) {
    double num{distr(eng)};
    return_vector.emplace_back(num);
  }
  // PrintVector(return_vector, size);
  return return_vector; 
}

void PrintVector(const std::vector<double>& return_vector, const int size){
  for (int i{0}; i < size; ++i) {
    std::cout << return_vector[i] << std::endl;
  }
}
