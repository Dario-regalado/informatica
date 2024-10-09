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
  return return_vector; 
}

double MaxNumber (const std::vector<double>& my_vector) {
  double max{my_vector[0]};
  for (int i{0}; i < my_vector.size(); ++i) {
    if (my_vector[i] > max) {
      max = my_vector[i];
    }
  }
  return max;
}
double MinNumber(const std::vector<double>& my_vector) {
  double min{my_vector[0]};
  for (int i{0}; i < my_vector.size(); ++i) {
    if (my_vector[i] < min) {
      min = my_vector[i];
    }
  }
  return min;
}

double PromediumNumber(const std::vector<double>& my_vector) {
  double promedium{0};
  for (int i{0}; i < my_vector.size(); ++i) {
    promedium += my_vector[i];
  }
  promedium /= my_vector.size();
  return promedium;
}