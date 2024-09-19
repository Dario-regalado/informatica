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
#include "language.h"
#include "alphabet.h"
#include "word.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */

void Usage(const int argc, char* argv[]);
void ExecuteInput(std::ifstream& input_file, std::ofstream& output_file, const int opcode);

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file;
  input_file.open(argv[1], std::ios::in);

  // si no se pudo abrir el archivo, salta error
  if(!input_file.is_open()) {
    std::cerr << "hubo un problema al abrir el archivo" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  
}


void ExecuteInput(std::ifstream& input_file, std::ofstream& output_file, const int opcode){
  while (input_file.good()){
    Alphabet alphabet;
    Word word;
    Language lenguaje;
    input_file >> word >> alphabet;
    switch (opcode) {
    case 1:
      output_file << alphabet << '\n';
      std::cout << alphabet << '\n';
      break;
    case 2:
      output_file << word.GetSize() << '\n';
      std::cout << word.GetSize() << '\n';
      break;
    case 3:
      output_file << word.Reverse() << '\n';
      std::cout << word.Reverse() << '\n';
      break;
    case 4:
      output_file << lenguaje.Prefijo(word) << '\n';
      std::cout << lenguaje.Prefijo(word) << '\n';
      break;
      /*
    case 5:
      
      break;
      */

    default:
      break;
    }
  }
  
}

void Usage(const int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " param 1, param 2\n";
    std::cerr << "Param 1: fichero de entrada de las cadenas\n";
    std::cerr << "Param 2: fichero de salida\n";
    std::cerr << "\n";
    std::exit(EXIT_FAILURE);
  }
}