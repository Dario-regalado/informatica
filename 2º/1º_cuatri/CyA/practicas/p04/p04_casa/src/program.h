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
  * @file cya P02 main
  */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "comments.h"
#include "variables.h"
#include "statements.h"

class Program {
 public:
  Program();
  Program(std::ifstream& input_stream, const std::string&);
  
  //getters
  Variables GetVariables() const { return variables_;}
  Statements GetStatemens() const {return statements_;}
  Comments GetComments() const {return comments_;}
  std::string GetName() const {return name_program_;}

  void EvaluateProgram(std::ifstream& input_stream, const std::string&);
  std::ostream& WriteDescription(std::ostream&) const;
  void IsMain(std::ostream&) const;

 private:
  std::string program_;
  std::string name_program_;
  Variables variables_;
  Statements statements_;
  Comments comments_;
};
std::ostream& operator<<(std::ostream&, const Program&);