/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief calculates the binomial coefficient for two given numbers
  * @bug There are no known bugs
  */

#include <iostream>
#include "funciones.h"

void Usage(const int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " X Y\n";
    std::cout << "Calculate the binomial coefficient for X and Y\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  int number1{std::stoi(argv[1])};
  int number2{std::stoi(argv[2])};
  std::cout << BinomialCalculator(number1, number2) << std::endl;
  return 0;
}