/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 18 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include <iostream>
#include <cstdlib>
#include "DependenciaLineal.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc != 1) {
    std::cerr << "Usage: " << argv[0] << " TEXT\n";
    std::cerr << "DESCRIPTION\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  int numero{0}, tamaño_vector{0}, dimension_base{0};
  std::cout << "introduzca la cantidad de vectores de la base y el tamaño de los vectores:";
  std::cin >> dimension_base >> tamaño_vector;
  std::vector<std::vector<int>> base(dimension_base);
  for (size_t i = 0; i < dimension_base; i++) {
    std::vector<int> vector{0};
    for (int i = 0; i < tamaño_vector; i++) {
      std::cin >> numero;
      vector.emplace_back(numero);
    }
    base.emplace_back(vector);
    vector.clear();
  }
  DepdendenciaLineal prueba1{base};
  return 0;
}
