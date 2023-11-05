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

void PrintProgramPurpose() {
  std::cout << "this program converts a binary number in decimal" << std::endl << std::endl;

}

bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber) {
  if (argc != kCorrectNumber) {
    std::cout << "This program has been executed with a wrong number of parameters" << std::endl;
    std::cout << "This program should be called " << argv[0] << " param1" << std::endl;
    std::cout << "param1: " << " A binary number" << std::endl;
    return false;
  }
  return true;
}

int BinaryDecimal(int binario){
  int decimal{0}, i{0}, resto{0};
  while (binario != 0) {
    resto = binario % 10;
    binario /= 10;
    if (resto != 0 && resto != 1) {
      return 0;
    }
    decimal += resto * std::pow(2, i);
    ++i;
  }
  return decimal;
}
