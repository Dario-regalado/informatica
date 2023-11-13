/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author NAME EMAIL 
  * @date Nov 12 2023
  * @brief DESCRIPTION
  * @bug There are no known bugs
  * @see
  */

#include "funciones.h"

int ScalarProduct(const std::vector<int>& imput_vector1, const std::vector<int>& imput_vector2){
  int result{0};
  for (int i{0}; i <= imput_vector1.size(); ++i) {
    result += imput_vector1[i] * imput_vector2[i];
  }
  return result;
}
