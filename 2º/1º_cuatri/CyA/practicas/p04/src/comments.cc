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

#include "Comments.h"


void Comments::EvaluateFile(std::ifstream& file_input) {
  std::string line;
  int line_match{0};
  bool inside_block_comment = false;
  std::string temp;

  while (getline(file_input, line)) {
    line_match++;

    if(std::regex_search(line, block_expression_)) {
      lines_.emplace_back(line_match, true);
      if(inside_block_comment) {
        ///////////////////////////////
        block_types_.push("DESCRIPTION");
        ///////////////////////////////
        inside_block_comment = false;
        continue;
      }
      inside_block_comment = true;
    }
    if(std::regex_search(line, inline_expression_)) {
      lines_.emplace_back(line_match, false);
      std::string result = std::regex_replace(line, inline_expression_, "");
      inline_types_.push(result);
    } 
  }
}


std::ostream& operator<<(std::ostream& output, const Comments& variable_salida) {
  output << "COMMENTS:\n";
  std::queue<std::string> block(variable_salida.GetBlockTypes());
  std::queue<std::string> line(variable_salida.GetInlineTypes());
  for (int i = 0; i < variable_salida.GetNumVar(); i++){
    output << "[Line ";
    if(variable_salida.GetLines().at(i).second) {
      output << variable_salida.GetLines().at(i).first << "-" << variable_salida.GetLines().at(i+1).first;
      i++;
      output  << "] " << block.front() << std::endl;
      block.pop();
    } else {
      output << variable_salida.GetLines().at(i).first;
      output << "] " << line.front() << std::endl;
      line.pop();
    }
  }
  
  return output;
}