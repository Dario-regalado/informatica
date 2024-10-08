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

#include "comments.h"

/**
 * @brief Construct a new Comments object
 * 
 * @param expresion_bloque 
 * @param expresion_linea 
 */
Comments::Comments(const std::regex& expresion_bloque, const std::regex& expresion_linea)  : block_expression_{R"((\/\*\*)[\s\S]*?(\*\/))", std::regex::ECMAScript | std::regex::multiline}, inline_expression_{R"(^(\/\/).*)", std::regex::ECMAScript | std::regex::multiline}  {
  if(expresion_bloque.mark_count() != 0)
    block_expression_ = expresion_bloque;
  if(!expresion_linea.mark_count() != 0)
    inline_expression_ = expresion_linea;
}


/**
 * @brief evalua el programa en busca de Comments
 * 
 * @param file_input 
 */
void Comments::EvaluateFile(const std::string& file_input) {
  // busca comentarios en bloque
  for (std::sregex_iterator it{file_input.begin(), file_input.end(), block_expression_}; it != std::sregex_iterator(); ++it) {
    std::smatch match = *it;
    std::regex description(R"(.*Universidad.*)");
    if(std::regex_search(match.str(), description))
      block_types_.push("DESCRIPTION");
    else
      block_types_.push(match.str());  // Almacena el bloque encontrado

    // Calcula la línea donde comienza la coincidencia
    auto match_start = file_input.begin() + match.position();
    int line_number = std::count(file_input.begin(), match_start, '\n') + 1;

    // Calcula la línea donde termina la coincidencia
    auto match_end = match_start + match.length();
    int final_line = std::count(file_input.begin(), match_end, '\n') + 1;

    // Guardar las líneas
    std::pair<int, int> temp(line_number, final_line);
    lines_.push(temp); 
  }

  // busca comentarios en linea
  for (std::sregex_iterator it{file_input.begin(), file_input.end(), inline_expression_}; it != std::sregex_iterator(); ++it) {
    std::smatch match = *it;
    inline_types_.push(match.str()); // Almacena el comentario encontrado

    auto match_line = file_input.begin() + match.position();
    int line = std::count(file_input.begin(), match_line, '\n') + 1;
    
    std::pair<int, int> temp(line, 0);
    lines_.push(temp); 
  }
}

/**
 * @brief imprime un Comment
 * 
 * @param output 
 * @param variable_salida 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& output, const Comments& variable_salida) {
  output << "COMMENTS:\n";
  std::queue<std::string> block(variable_salida.GetBlockTypes());
  std::queue<std::string> line(variable_salida.GetInlineTypes());
  std::queue<std::pair<int, int>> lines(variable_salida.GetLines());
  
  // primero imprimo los comentarios en bloque
  for (unsigned i = 0; i < variable_salida.GetBlockTypes().size(); i++) {
    output << "[Line ";
    output << lines.front().first << "-" << lines.front().second;
    lines.pop();
    output  << "] " << block.front() << std::endl;
    block.pop();
  }
  // imprime los comentarios en linea
  for (unsigned i = 0; i < variable_salida.GetInlineTypes().size(); i++) {
    output << "[Line ";
    output << lines.front().first;
    lines.pop();
    output  << "] " << line.front() << std::endl;
    line.pop();
  }
  return output;
}
