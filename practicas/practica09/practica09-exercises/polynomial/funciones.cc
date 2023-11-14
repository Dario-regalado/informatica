/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 12 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */ 

#include "funciones.h"


int FuncionRara (const std::vector<int>& coefficients, int value){
  int result{coefficients[0] * value + coefficients[1]};
  for (int i{2}; i < coefficients.size(); ++i) {
    result *= value;
    result += coefficients[i];
  }
  return result;
}