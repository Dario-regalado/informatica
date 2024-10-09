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

#include <iostream>

void LeapYear (int year) {
  if (year < 9999 && year > 1000) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}

int main() {
  int n_suceciones{0};
  std::cin >> n_suceciones;
  LeapYear(n_suceciones);
  return 0;
}