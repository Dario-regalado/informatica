/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief print the first position of a char in a string
  * @bug There are no known bugs
  */

#include <iostream>
#include "funciones.h"

void Usage(const int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " TEXT CHAR\n";
    std::cout << "print the first position of a char in a string\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char* argv[]){
  Usage(argc, argv);
  std::cout << letterPosition(std::string(argv[1]), char(argv[2][0])) << std::endl;
  return 0;
}
