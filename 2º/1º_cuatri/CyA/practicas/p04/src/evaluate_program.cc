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
  * @file cya P02 evaluate_program
  */

#include <iostream>
#include <fstream>
#include <string>
#include "variables.h"
#include "statements.h"
#include "comments.h"

void Usage(const int argc, char* argv[]);
void EvaluateProgram(std::ifstream&, std::ofstream&);

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file;
  std::ofstream output_file;
  input_file.open(argv[1], std::ios::in);
  output_file.open(argv[2], std::ios::out); //escribe sin sobreescribir datos
  if(!input_file.is_open() || !output_file.is_open())
    std::cout <<"no se abrieron los archivos\n";
  
  EvaluateProgram(input_file, output_file);
  return 0;
}


void EvaluateProgram(std::ifstream& input_stream, std::ofstream& output_stream){
  Comments var;
  var.EvaluateFile(input_stream);
  output_stream << var;
  std::cout << var << std::endl;
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
    std::cerr << "Usage: " << argv[0] << " param 1, param 2, param 3\n";
    std::cerr << "Param 1: \n";
    std::cerr << "Param 2: \n";
    std::cerr << "Param 3: :\n";
    std::exit(EXIT_FAILURE);
  } else if(argc != 3){
    std::cerr << "Modo de empleo: " << argv[0] << " filein.txt fileout.txt opcode\n";
    std::cerr << "Pruebe " << argv[0] << "--help para mas informacion.\n";
    std::exit(EXIT_FAILURE);
  }
}