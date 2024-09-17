/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 21 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include <iostream>
#include <cstdlib>
#include "Anillo.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " TEXT\n";
    std::cerr << "DESCRIPTION\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  Anillo anillo1{std::stoi(argv[1]), std::stoi(argv[2])}, anilo_sumador{};

  std::cout << anillo1 << std::endl;
  anillo1 = anillo1 * 5;  
  std::cout << anillo1 << std::endl;
  std::cin >> anilo_sumador;
  std::cout << anillo1 << std::endl;

  return 0;
}
