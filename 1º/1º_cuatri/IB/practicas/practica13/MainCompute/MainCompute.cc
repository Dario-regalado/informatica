/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 13 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include <iostream>
#include <cstdlib>
#include "ComputeInt.h"

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
  ComputeInt compute{std::stoi(argv[1]), std::stoi(argv[2])};
  std::cout << compute.Factorial() << std::endl;
  std::cout << compute.SumSerie() << std::endl;
  std::cout << compute.IsPrime() << std::endl;
  std::cout << compute.IsPerfect() << std::endl;
  std::cout << compute.AreRelativePrimer() << std::endl;
  return 0;
}
