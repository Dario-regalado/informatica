/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief sum the digits of an imput
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include "funciones.h"

void PrintProgramPurpose() {
  std::cout << "this program sum the digits of an imput" << std::endl << std::endl;

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

int SumOfDigits(const std::string& imput_number) {
  int final_number{0};
  for (int i = 0; i < imput_number.length(); i++) {
    char digit{imput_number[i]};
    int numeric_value{digit - '0'};
    final_number += numeric_value;
  }
  return final_number;
}