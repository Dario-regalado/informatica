/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 08/10/2024
  * @brief definition of the Statements class 
  * @Practica 04_regex
  * @bug There are no known bugs
  * @file cya P02 main
  */

#pragma once
#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <string>

class Statements {
 public:
  Statements() : expression_{R"(^\s+(switch).*\(\s*(.*)\s*\)|\b(for|while)\b)", std::regex::ECMAScript|std::regex::multiline} {}
  Statements(const std::regex&);

  //getter
  int GetNumVar() const {return std::min(lines_.size(), std::min(variable_names_.size(), types_.size()));}
  std::vector<int> GetLines() const {return lines_;}
  std::vector<std::string> GetTypes() const {return types_;}
  std::vector<std::string> GetVarName() const {return variable_names_;}

  void EvaluateFile(const std::string&);

 private:
  std::regex expression_;
  std::vector<int> lines_;
  std::vector<std::string> variable_names_;
  std::vector<std::string> types_;
};

std::ostream& operator<<(std::ostream&, const Statements&);