/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 21 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "dependencies.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc != 5) {
    std::cerr << "Usage: " << argv[0] << " TEXT\n";
    std::cerr << "DESCRIPTION\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  std::string input1{argv[2]};
  std::string input2{argv[4]};

  std::vector<double> vector1{CreateVector(input1)};
  std::vector<double> vector2{CreateVector(input2)};
  std::vector<double> concatenated_vector{ConcatenateVector(vector1, vector2)};
  return 0;
}
