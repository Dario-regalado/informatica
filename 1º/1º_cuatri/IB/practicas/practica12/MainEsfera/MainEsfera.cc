/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 14 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include <iostream>
#include <cstdlib>
#include "Esfera.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << std::endl;;
    std::cerr << "First number is the radius of the sphere\n";
    std::cerr << "Second number is the mass of the sphere\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  Esfera mi_esfera{std::stod(argv[1]), std::stod(argv[2])};
  std::cout << "el area superficial de la esfera es: " << mi_esfera.AreaSuperficial() << std::endl;
  std::cout << "el volumen de la esfera es: " << mi_esfera.Volumen() << std::endl;
  std::cout << "La densidad volumetrica de la esfera es: " << mi_esfera.Densidad() << std::endl;
  return 0;
}
