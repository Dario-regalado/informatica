/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 21 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "dependencies.h"

std::vector<double> CreateVector(const std::string& vector) {
  std::vector<double> vector_return{};
  for (int i{0}; i < vector.length(); ++i) {
    vector_return.emplace_back((vector));
  }
  
  
  
  /*for (int i{0}; i < vector.length(); ++i) {
    if (!std::isblank(vector[i])) {
      vector_return.emplace_back(vector[i]);
      // std::cout << vector[i] << " " << std::endl;
    } else {
      continue;
    }
  }*/
  return vector_return;
}

std::vector<double> ConcatenateVector (const std::vector<double>& vector1, const std::vector<double>& vector2) {
  std::vector<double> result;
  for (const auto& value : vector1) {
    result.push_back(value);
    std::cout << value << std::endl;
  }
  for (const auto& value : vector2) {
    result.push_back(value);
    std::cout << value << std::endl;
  }
  return result;
}