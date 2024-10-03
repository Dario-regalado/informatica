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
#include <regex>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>

class Comments {
 public:
  Comments() : block_expression_{R"(^(\/\*)|^[\s]*(\*\/))"}, inline_expression_{R"(^(\/\/))"} {}

  //getter
  int GetNumVar() const {return lines_.size();}
  std::vector<std::pair<int, bool>> GetLines() const {return lines_;}
  std::queue<std::string> GetInlineTypes() const {return inline_types_;}
  std::queue<std::string> GetBlockTypes() const {return block_types_;}

  void EvaluateFile(std::ifstream&);

 private:
  std::regex block_expression_;
  std::regex inline_expression_;
  std::vector<std::pair<int, bool>> lines_;
  std::queue<std::string> block_types_;
  std::queue<std::string> inline_types_;
};

std::ostream& operator<<(std::ostream&, const Comments&);