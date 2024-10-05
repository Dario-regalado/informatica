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
 * @param input_expre 
 */
Statements::Statements(const std::regex& input_expre) : expression_{R"(\b(for|while)\b)", std::regex::ECMAScript|std::regex::multiline} {
  if(input_expre.mark_count() != 0)
    expression_ = input_expre;
  lines_.resize(0);
  variable_names_.resize(0);
  types_.resize(0);
}


/**
 * @brief evalua el programa en busca de statements
 * 
 * @param file_input 
 */
void Statements::EvaluateFile(const std::string& file_input) {
  for (std::sregex_iterator it{file_input.begin(), file_input.end(), expression_}; it != std::sregex_iterator(); ++it) {
    std::smatch match = *it;

    //calculamos la linea de coincidencia
    auto match_pos = file_input.begin() + match.position();
    int line = std::count(file_input.begin(), match_pos, '\n') + 1;
    lines_.emplace_back(line);

    //verificamos si es for o while
    if(std::regex_search(match.str(), std::regex("for|while"))) {
      types_.emplace_back("LOOP");
      // añadimos si es for o while
      if(std::regex_search(match.str(), std::regex("for")))
        variable_names_.emplace_back("for");
      else
        variable_names_.emplace_back("while");
    }
    else
      types_.emplace_back("otra cosa");
  }
}

/**
 * @brief imprime un Statement
 * 
 * @param output 
 * @param variable_salida 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& output, const Statements& variable_salida) {
  output << "STATEMENTS:\n";
  for (int i = 0; i < variable_salida.GetNumVar(); i++){
    output << "[Line " << variable_salida.GetLines().at(i)  << "] " << variable_salida.GetTypes().at(i) 
    << ": " << variable_salida.GetVarName().at(i) << std::endl;
  }
  return output;
}