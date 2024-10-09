/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 12 2023
  * @brief scalar product of two imput vectors
  * @bug There are no known bugs
  * @see
  */


#include "funciones.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc < 1) {
    std::cerr << "Usage: " << argv[0] << " TEXT\n";
    std::cerr << "scalar product of two imput vectors\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  std::vector<int> vector1{}, vector2{};
  int numero_imputs{((argc - 1) / 2)};
  if (argc % 2 == 1) {
    for (int i{1}; i <= numero_imputs; ++i) {
      vector1.emplace_back(std::stoi(argv[i]));
      std::cout << argv[i];
    }  
    std::cout << std::endl;
    for (int i = numero_imputs + 1; i <= argc - 1; ++i) {
      vector2.emplace_back(std::stoi(argv[i]));
      std::cout << argv[i];
    }
    std::cout << std::endl;
  }
  std::cout << ScalarProduct(vector1, vector2);
  return 0;
}
