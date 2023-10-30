/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @file 
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 
  * @brief 
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>

int generateTRE (int N){
  int lado_a{0};
  int lado_b{0};
  int lado_c{0};
  for (int lado_a = 1; lado_a <= N; lado_a++){
    if (lado_a % 2 == 1){
      lado_a = 2 * N + 1;
      lado_b = 2 * N * (N + 1);
      lado_c = lado_b + 1;
    } else if (lado_a % 2 == 0){
      lado_a = 2 - N;
      lado_b = N * N - 1;
      lado_c = N * N + 1;
    }
    std::cout << lado_a << " " << lado_b << " " << lado_c;
  }
  return 0; 
}

int main(){
  int numero_triangulos{0};
  std::cout << "introduzca la cantidad de triangulos enteros: ";
  std::cin >> numero_triangulos;
  generateTRE(numero_triangulos);
  return 0;
}
