/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief converts a binary num in decimal
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include "funciones.h"

int main(const int agrc, char* argv[]) {
  PrintProgramPurpose();
  if (!CheckCorrectParameters(agrc, argv, 2)) {
    return 1;
  }
  std::cout << BinaryDecimal(std::stoi(argv[1])) << std::endl;
  return 0;
}