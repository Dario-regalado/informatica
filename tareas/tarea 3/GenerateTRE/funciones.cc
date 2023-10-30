/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief generate a Triangle Rectangle N-times
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */
#include "funciones.h"

int generateTRE (int N){
  for (int i = 1; i <= N; i++) {
  int lado_a{0};
  int lado_b{0};
  int lado_c{0};
  int number_k{0};
    if (i % 2 == 0){
      lado_a = i;
      number_k = lado_a / 2;
      lado_b = number_k * number_k - 1;
      lado_c = number_k * number_k + 1;
    } else {
      lado_a = i;
      number_k = (lado_a - 1) / 2;
      lado_b = 2 * number_k * (number_k + 1);
      lado_c = lado_b + 1;
    }
    if (lado_a <= lado_b && lado_b <= lado_c) {
      std::cout << lado_a << " " << lado_b << " " << lado_c << std::endl;
    }   
  }
  return 0; 
}