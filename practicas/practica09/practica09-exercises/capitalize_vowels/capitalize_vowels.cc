/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 12 2023
  * @brief capitalize vowels and lowercase consonants
  * @bug There are no known bugs
  * @see
  */

#include "funciones.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " must be a string\n";
    std::cerr << "capitalize vowels and lowercase consonants\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  string imput_word{argv[1]};
  std::cout << CapitalizeVowels(imput_word) << std::endl;
  return 0;
}
