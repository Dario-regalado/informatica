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
  // imprimo los comentarios en linea
  for (unsigned i = 0; i < variable_salida.GetInlineTypes().size(); i++) {
    output << "[Line ";
    output << lines.front().first;
    lines.pop();
    output  << "] " << line.front() << std::endl;
    line.pop();
  }
  return output;
}

/*

for (int i = 0; i < variable_salida.GetNumVar(); i++){
    output << "[Line ";
    if(lines.at(i).second) {
      output << lines.at(i).first << "-" << lines.at(i+1).first;
      i++;
      output  << "] " << block.front() << std::endl;
      block.pop();
    } else {
      output << lines.at(i).first;
      output << "] " << line.front() << std::endl;
      line.pop();
    }
  }


for (unsigned i = 0; i < file_input.size(); i++){
    if(file_input[i] == '\n')
      n_lineas++;
  }
  
  if(std::regex_search(file_input, match_block, block_expression_)) {
    for(const auto& element : match_block) {
      block_types_.push(element.str());
      int n_lines{0};
      for (unsigned i = 0; i < element.str().size(); i++){
        if(element.str().at(i) == '\n'){
          n_lines++;
        }
      }
      if(lines_.size() == 0)
        lines_.emplace_back(0, 0);
      lines_.emplace_back(n_lineas - n_lines, true);
    }
  }
  if(std::regex_search(file_input, match_line, inline_expression_)) {

    for(const auto& element : match_line) {
      inline_types_.push(element);
    }
  } 
  */