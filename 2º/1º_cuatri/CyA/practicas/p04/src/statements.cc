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

#include "Statements.h"


/**
 * @brief Construct a new Statements object
 * 
 * @param  
 */
Statements::Statements(const std::regex& input_expresion) {
  expression_ = input_expresion;
  lines_.resize(0);
  types_.resize(0);
  variable_names_.resize(0);
}

/* revisar por los tipos de statements
void Statements::EvaluateFile(std::ifstream& input_file) {
  std::string line;
  std::smatch matches;
  int line_match{0};
  
  while(getline(input_file, line)) {
    line_match++;

    if(std::regex_search(line, expression_)) {
      lines_.emplace_back(line_match);

      if(std::regex_search(line, std::regex("for")))
        types_.emplace_back("FOR");
      else  
        types_.emplace_back("WHILE");
      
      std::string var_result = std::regex_replace(line, std::regex(R"(\b(?!for\b|while\b)\w+\b)"), "");
      var_result.erase(var_result.size()-2);
      variable_names_.emplace_back(var_result);
    }
  }
}
*/

std::ostream& operator<<(std::ostream& output, const Statements& variable_salida) {
  output << "STATEMENTS:\n";
  for (int i = 0; i < variable_salida.GetNumVar(); i++){
    output << "[Line " << variable_salida.GetLines().at(i)  << "] " << variable_salida.GetTypes().at(i) 
    << ": " << variable_salida.GetVarName().at(i) << std::endl;
  }
  return output;
}