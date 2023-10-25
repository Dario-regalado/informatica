/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @file P90615_print_the_higher_number.cc
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 22 Oct 2023
  * @brief print the higher number of three imputs
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>

int main() {
  int numero1{0}; 
  int numero2{0}; 
  int numero3{0};

  std::cin >> numero1 >> numero2 >> numero3;
  int numeroMayor{numero1};
  if (numero2 > numeroMayor){
    numeroMayor = numero2;
  }
  else if (numero3 > numeroMayor){
    numeroMayor = numero3;
  }
  std::cout << numeroMayor << std::endl;
  return 0;
}
