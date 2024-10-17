/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 
  * @brief 
  * @Practica 
  * @bug There are no known bugs
  * @file cya P02 automata_finito
  */

#include <iostream>
#include <fstream>
#include <algorithm> // Necesario para std::all_of
#include <string>
#include "Automata.h"

void Usage(const int argc, char* argv[]);
void AnalizeWords(Automata&, std::ifstream&);

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream automata_file;
  std::ifstream words_file;
  automata_file.open(argv[1]);
  words_file.open(argv[2]);
  if(!automata_file.is_open() || !words_file.is_open())
    std::cerr << "archivos no abiertos\n";
    
  Automata automata(automata_file);
  AnalizeWords(automata, words_file);
  return 0;
}


/** @brief Shows correct usage of the program. 
  *        If the program wasn't run correctly, prints the
  *        help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cerr << "Usage: " << argv[0] << " file_automata.fa, file_words.txt,\n";
    std::cerr << "file_automata.fa: file with the definition of the automata\n";
    std::cerr << "file_words.txt: file with the words to check\n";
    std::exit(EXIT_FAILURE);
  } else if(argc != 3){
    std::cerr << "Modo de empleo: " << argv[0] << " file_automata.fa file_words.txt\n";
    std::cerr << "Pruebe " << argv[0] << "--help para mas informacion.\n";
    std::exit(EXIT_FAILURE);
  }
}

void AnalizeWords(Automata& automata, std::ifstream& words_file) {
  std::string line;
  while (words_file >> line) {
    // Verificar si la línea leída no está vacía o no contiene solo espacios
    std::cout << line << " --- ";
    automata.AnalizeWords(line) ? std::cout << "Accepted\n" : std::cout << "Rejected\n";
  }
}
