/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief 
  * @bug There are no known bugs
  * @file 
  */
 
#include <iostream>
#include <fstream>
#include <set>
#include "clase.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " param 1, param 2\n";
    std::cerr << "Param 1: fichero de entrada de las cadenas\n";
    std::cerr << "Param 2: fichero de salida\n";
    std::cerr << "\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file;
  input_file.open(argv[1], std::ios::in);

  // si no se pudo abrir el archivo, salta error
  if(!input_file.is_open()) {
    std::cerr << "hubo un problema al abrir el archivo" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  
  /////////////// arreglar y preguntar
  /*
  std::string iterador;
  while(getline(input_file, iterador)) {

  }
  */
  Language letters("abbab", "ab");
  std::cout << letters.Alfabeto() << std::endl;

}