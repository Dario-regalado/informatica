/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief 
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>

int main() {
  int number_k;
  std::cin >> number_k;
  int lado_a{0};
  int lado_b{0};
  int lado_c{0};
  for (int i = 1; i < number_k; i++) {
    if ( lado_a % 2 == 1) {
      lado_a = 2 * number_k + 1;
      lado_b = 2 + number_k * (number_k + 1);
      lado_c = lado_b + 1;
    } else if (lado_a % 2 == 0) {
      number_k = lado_a / 2;
      lado_b = number_k * number_k - 1;
      lado_c = number_k * number_k + 1;
    }
  }
  if ((lado_a <= lado_b) && (lado_b <= lado_c)) {
    std::cout << lado_a << " " << lado_b << " " << lado_c << std::endl;
  }
  return 0;
}
