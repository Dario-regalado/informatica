/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief converts a decimal number in binary
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

int DecimalBinary(int decimal_number) {
  int digit_value{1};
  while (digit_value * 2 <= decimal_number) {
    digit_value *= 2;
  }

  while (decimal_number != 0 || digit_value != 0) {
    if (decimal_number >= digit_value) {
      std::cout << 1;
      decimal_number -= digit_value;
    } else {
      std::cout << 0;
    }
    digit_value /= 2;
  }
  std::cout << '\n';
}
