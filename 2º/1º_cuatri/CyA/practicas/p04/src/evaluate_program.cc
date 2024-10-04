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
#include <sstream>
#include <regex>
#include "variables.h"
#include "statements.h"
#include "comments.h"


void WriteDescricion(std::ifstream&, std::ofstream&);
void Usage(const int argc, char* argv[]);
void EvaluateProgram(std::ifstream&, std::ofstream&, char* argv[]);

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file;
  std::ofstream output_file;
  input_file.open(argv[1], std::ios::in);
  output_file.open(argv[2], std::ios::out); 
  if(!input_file.is_open() || !output_file.is_open())
    std::cout <<"no se abrieron los archivos\n";
  
  EvaluateProgram(input_file, output_file, argv);
  return 0;
}


void EvaluateProgram(std::ifstream& input_stream, std::ofstream& output_stream, char* argv[]){
  Variables var;
  var.EvaluateFile(input_stream);
  Comments comments;
  comments.EvaluateFile(input_stream);
  //ºStatements estatutos;
  //ºestatutos.EvaluateFile(input_stream);

  output_stream << "PROGRAM: " << argv[1] << std::endl;
  WriteDescricion(input_stream, output_stream);
  output_stream << var << std::endl;
  //output_stream << estatutos << std::endl;
  output_stream << comments << std::endl;
}

// ^(\/\*)[\s\S]*?(\*\/)$ para el comentario en bloque del inicio
void WriteDescricion(std::ifstream& file_input, std::ofstream& output_stream) {
  //carga el archivo en un string
  std::stringstream buffer_in;
  buffer_in << file_input.rdbuf();
  std::string file_content = buffer_in.str();

  std::regex description_comment(R"(\/\*\*[\s\S]*?\*\/)", std::regex::ECMAScript);
  std::smatch matches;
  std::string description;
  if(std::regex_search(file_content, matches, description_comment, std::regex_constants::match_continuous)) {
    std::cout << "match";
    description = matches.str();
  }
  output_stream << "DESCRIPTION:\n" << description;
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