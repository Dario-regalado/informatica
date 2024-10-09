/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 20 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include <iostream>
#include <cstdlib>
#include "dependencies.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " TEXT\n";
    std::cerr << "DESCRIPTION\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  std::vector<double> my_vector = GenerateVector(std::stoi(argv[1]), std::stod(argv[2]), std::stod(argv[3]));
  for (int i{0}; i < my_vector.size(); ++i) {
    std::cout << my_vector[i] << " ";
  }
  std::cout << std::endl;
  std::cout << ReduceSum(my_vector) << std::endl;
  return 0;
}
