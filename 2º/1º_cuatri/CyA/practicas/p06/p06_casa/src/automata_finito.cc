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
#include <string>
#include "Automata.h"

void Usage(const int argc, char* argv[]);
void AnalizeWords(std::ifstream&, std::ifstream&);

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream automata_file;
  automata_file.open(argv[1], std::ios::in);
  std::ifstream words_file;
  words_file.open(argv[2], std::ios::in);
  if(!automata_file.is_open() || !words_file.is_open())
    std::cerr << "archivos no abiertos\n";
  AnalizeWords(automata_file, words_file);
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

void AnalizeWords(std::ifstream& automata_file, std::ifstream& words_file) {
  Automata automata;
  automata.AnalizeAutomata(automata_file);
  std::string line;

  while(std::getline(words_file, line)) {
    std::cout << line << " --- ";
    automata.AnalizeWords(line) ? std::cout << "Accepted\n" : std::cout << "Rejected\n";
  }
}