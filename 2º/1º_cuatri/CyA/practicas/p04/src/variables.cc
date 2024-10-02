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

#include "variables.h"


/**
 * @brief Construct a new Variables object
 * 
 * @param  
 */
Variables::Variables(const std::regex& input_expression){
  expression_ = input_expression;
  lines_.resize(0);
  types_.resize(0);
  variable_names_.resize(0);
}


void Variables::EvaluateFile(std::ifstream& file_input) {
  std::string line;
  std::smatch matches;
  int line_match{0};
  
  while(getline(file_input, line)) {
    line_match++;

    // Comprobamos si la línea tiene una coincidencia con la expresión regular
    if (std::regex_search(line, expression_)){
      lines_.emplace_back(line_match);

      //verificamos si es int o double
      if(std::regex_search(line, std::regex("int")))
        types_.emplace_back("INT");
      else
        types_.emplace_back("DOUBLE");

      // Reemplazamos lo que coincide con la expresión regular
      std::string result = std::regex_replace(line, std::regex("(\\s+(int|double)\\s)"), "");
      result.erase(result.size()-2);
      variable_names_.emplace_back(result);
    }
  }
}


std::ostream& operator<<(std::ostream& output, const Variables& variable_salida) {
  output << "VARIABLES:\n";
  for (int i = 0; i < variable_salida.GetNumVar(); i++){
    output << "[Line " << variable_salida.GetLines().at(i)  << "] " << variable_salida.GetTypes().at(i) 
    << ": " << variable_salida.GetVarName().at(i) << std::endl;
  }
  return output;
}