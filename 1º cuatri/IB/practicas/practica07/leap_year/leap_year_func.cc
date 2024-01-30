/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief check if the imput year is leap year
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include "funciones.h"

void PrintProgramPurpose() {
  std::cout << "this program check if the imput year is leap year" << std::endl << std::endl;

}

bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber) {
  if (argc != kCorrectNumber) {
    std::cout << "This program has been executed with a wrong number of parameters" << std::endl;
    std::cout << "This program should be called " << argv[0] << " param1" << std::endl;
    std::cout << "param1: " << " A entire number" << std::endl;
    return false;
  }
  return true;
}

void LeapYear (int year) {
  if (year < 9999 && year > 1000) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}