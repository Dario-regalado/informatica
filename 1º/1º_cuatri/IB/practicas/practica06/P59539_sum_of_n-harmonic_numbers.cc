/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @file P59539_sum_of_n-harmonic_numbers.cc
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 22 Oct 2023
  * @brief sum of the imput-harmonic numbers
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>
#include <iomanip>

int main() {
  int numero1{0};
  double suma_encadenada{0.0};

  std::cin >> numero1;
  for (int i = 1; i <= numero1; i++){
    suma_encadenada += (1.0 / i); 
  }
  std::cout << std::fixed << std::setprecision(4) << suma_encadenada << std::endl;
  return 0;
}
