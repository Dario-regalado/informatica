/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief prints the N first terms of fibonacci serie
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include "funciones.h"

void PrintProgramPurpose() {
  std::cout << "this program prints the N first terms of fibonacci serie" << std::endl << std::endl;

}

bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber) {
  if (argc != kCorrectNumber) {
    std::cout << "This program has been executed with a wrong number of parameters" << std::endl;
    std::cout << "This program should be called " << argv[0] << " param1" << std::endl;
    std::cout << "param1: " << " An integer number to be sumed itself" << std::endl;
    return false;
  }
  return true;
}

int FibonacciSerie(const int& N) {
  int serie1{0};
  int serie2{1};
  for (int i = 0; i < (N - 1); i++) {
    std::cout << serie1 << " ";
    int temp{serie1 + serie2};
    serie1 = serie2;
    serie2 = temp;   
  }
  return serie1;
}