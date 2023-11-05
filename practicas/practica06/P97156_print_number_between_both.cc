/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @file P97156_print_number_between_both.cc
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 22 Oct 2023
  * @brief print the numbers between two imputs
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>

int main() {
  int numero1{0};
  int numero2{0};
    
  std::cin >> numero1 >> numero2;
  int intervalo = numero2 - numero1;
  if (numero2 < numero1){
    std::cout << std::endl;
    return 0;
  }
  for (int i = 0; i < intervalo; i++){
    std::cout << numero1 << ",";
    ++numero1;
  }
  std::cout << numero2 << std::endl;
  return 0;
}
