/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief generate a Triangle Rectangle N-times
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>
#include "funciones.h"

void Usage(const int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " TEXT\n";
    std::cout << "generate a Triangle Rectangle N-times\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char* argv[]){
  Usage(argc, argv);
  int number{std::stoi(argv[1])};
  generateTRE(number);
  return 0;
}
