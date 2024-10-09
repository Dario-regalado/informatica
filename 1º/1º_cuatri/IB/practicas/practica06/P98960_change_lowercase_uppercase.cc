/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @file P98960_change_lowercase_uppercase.cc
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 22 Oct 2023
  * @brief change a word in lowercase to uppercase and vice verse
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>

int main() {
  char letra_a_convertir{0};
   
  std::cin >> letra_a_convertir;
  if (islower(letra_a_convertir)){
    char letramayuscula = static_cast<char>(letra_a_convertir - 32);
    std::cout << letramayuscula << std::endl;
  } else if (isupper(letra_a_convertir)){
      char letraminuscula = static_cast<char>(letra_a_convertir + 32);
      std::cout << letraminuscula << std::endl;
  }    
  return 0;
}
