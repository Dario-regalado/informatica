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
#include <vector>
#include <utility>
#include <queue>

class Comments {
 public:
  Comments() : block_expression_{R"((\/\*\*)[\s\S]*?(\*\/))", std::regex::ECMAScript | std::regex::multiline}, inline_expression_{R"(^(\/\/).*)", std::regex::ECMAScript | std::regex::multiline} {}

  //getter
  int GetNumVar() const {return lines_.size();}
  std::queue<std::pair<int, int>> GetLines() const {return lines_;}
  std::queue<std::string> GetInlineTypes() const {return inline_types_;}
  std::queue<std::string> GetBlockTypes() const {return block_types_;}

  void EvaluateFile(const std::string&);

 private:
  std::regex block_expression_;
  std::regex inline_expression_;
  std::queue<std::pair<int, int>> lines_;
  std::queue<std::string> block_types_;
  std::queue<std::string> inline_types_;
};

std::ostream& operator<<(std::ostream&, const Comments&);