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
 * @param input_expression 
 */
Variables::Variables(const std::regex& input_expression) : expression_{R"(^\s+(int|double)\s+([a-zA-Z_]\w+)([^a-zA-Z]*)\;$)", std::regex::ECMAScript | std::regex::multiline} {
  if(input_expression.mark_count() != 0)
    expression_ = input_expression;
  lines_.resize(0);
  types_.resize(0);
  variable_names_.resize(0);
}

/**
 * @brief evalua el programa en busca de Variables
 * 
 * @param file_input 
 */
void Variables::EvaluateFile(const std::string& file_input) {
  for (std::sregex_iterator it{file_input.begin(), file_input.end(), expression_}; it != std::sregex_iterator(); it++) {
    std::smatch match = *it;

    // Calculamos la línea de coincidencia
    auto match_pos = file_input.begin() + match.position();
    int line = std::count(file_input.begin(), match_pos, '\n') + 2;
    lines_.emplace_back(line);

    // Verificamos si es int o double
    if (match.str(1) == "int") {
      types_.emplace_back("INT");
    } else {
      types_.emplace_back("DOUBLE");
    }

    // Obtenemos el nombre de la variable
    std::string variable_name = match.str(2) + (match.str(3).size() == 0? "" : match.str(3));
    variable_names_.emplace_back(variable_name);
  }
}


/**
 * @brief imprime una Variable
 * 
 * @param output 
 * @param variable_salida 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& output, const Variables& variable_salida) {
  output << "VARIABLES:\n";
  for (int i = 0; i < variable_salida.GetNumVar(); i++){
    output << "[Line " << variable_salida.GetLines().at(i)  << "] " << variable_salida.GetTypes().at(i) 
    << ": " << variable_salida.GetVarName().at(i) << std::endl;
  }
  return output;
}