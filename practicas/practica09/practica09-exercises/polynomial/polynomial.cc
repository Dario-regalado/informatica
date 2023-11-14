/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 12 2023
  * @brief calcule el valor del polinomio correspondiente en el valor dado
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
    std::cerr << "Usage: " << argv[0] << " introduce a number\n";
    std::cerr << "calcule el valor del polinomio correspondiente en el valor dado\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  std::vector<int> vector1{};
  int value{std::stoi(argv[argc - 1])};
  for (int i{1}; i < argc - 1; ++i) {
    vector1.emplace_back(std::stoi(argv[i]));
  }
  std::cout << FuncionRara(vector1, value) << std::endl;
  return 0;
}
