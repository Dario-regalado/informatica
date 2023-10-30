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
#include "funciones.h"

int main(){
  std::string string1{0};
  std::cout << "introduzca la palabra a analizar: ";
  std::getline(std::cin, string1);
  std::cout << "el numero de vocales es; " << countVowels(string1) << std::endl;
  return 0;
}