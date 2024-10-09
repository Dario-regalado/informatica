/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief count the vowels in a string
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */
#include "funciones.h"

void Usage(const int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " TEXT\n";
    std::cout << "count the vowels in a string\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char* argv[]){
  Usage(argc, argv);
  std::cout << "el numero de vocales es; " << countVowels(std::string(argv[1])) << std::endl;
  return 0;

}