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

#include "dependencies.h"
#include <vector>

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
  std::vector<double> my_vector{GenerateVector(std::stoi(argv[1]), std::stod(argv[2]), std::stod(argv[3]))};
  for (const auto& value : my_vector) {
    std::cout << "Component: " << value << std::endl;
  }
  return 0;
}
