/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 08/10/2024
  * @brief main program
  * @Practica 04_regex
  * @bug There are no known bugs
  * @file cya P02 evaluate_program
  */

#include <iostream>
#include "program.h"

void Usage(const int argc, char* argv[]);

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file;
  std::ofstream output_file;
  input_file.open(argv[1], std::ios::in);
  output_file.open(argv[2], std::ios::out); 
  
  if(!input_file.is_open())
    std::cerr << "no pudo abrir el programa\n";
  if(!output_file.is_open())  
    std::cerr << "no pudo abrir el archivo de salida\n";
  
  Program programa1(input_file, argv[1]);
  output_file << programa1;
  input_file.close();
  output_file.close();
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
    std::cerr << "Usage: " << argv[0] << " program_in.cc file_out.txt\n";
    std::cerr << "program_in.cc: the program to be analized\n";
    std::cerr << "file_out.txt: the file were the output will be written\n";
    std::exit(EXIT_FAILURE);
  } else if(argc != 3){
    std::cerr << "Modo de empleo: " << argv[0] << " program_in.cc file_out.txt\n";
    std::cerr << "Pruebe " << argv[0] << " --help para mas informacion.\n";
    std::exit(EXIT_FAILURE);
  }
}