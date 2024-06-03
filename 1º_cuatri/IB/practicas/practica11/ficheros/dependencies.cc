/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 30 2023
  * @brief combine two files into another file
  * @bug There are no known bugs
  * @see
  */

#include "dependencies.h"

/*
 * Print an error message
 */

void Print() {
  std::cerr << "couldn't open the files" << std::endl;
}

/*
 * Conbine two alternatives files into another file
 * 
 * @param[in] first_file The first file to combine
 * @param[in] second_file The second file to combine
 * return a file with the combination
 */

void ConbineWords (std::ifstream &first_file, std::ifstream &second_file) {
  std::ofstream output_file("salida.txt");
  if (!first_file.is_open() && !second_file.is_open()) {
    Print;
  }
  int size_output_file (first_file.width() + second_file.width());
  std::string word1;
  std::string word2;
  while (first_file && second_file) {
    first_file >> word1;
    second_file >> word2;
    output_file << word1 << " " << word2 << " ";
  }
  first_file.close();
  second_file.close();
  output_file.close();
}
