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

#include <iostream>
#include "dependencies.h"

void Fecha::AnoBisiesto() {
  if ((year_ % 4 == 0 && year_ % 100 != 0 || year_ % 400 == 0)){
  std::cout << "el ano es bisiesto" << std::endl;
  } else{
    std::cout << "el ano no es bisiesto" << std::endl;
  }
}
bool Fecha::is_valid_date(int d, int m, int y) {
  if (d > 0 && d <= 31 && m > 0 && m <= 12 && y <= 9999 && y > 1800) {
    if ((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d <= 29) {
      return true;
    } 
  } else{
    return false;
  }
}