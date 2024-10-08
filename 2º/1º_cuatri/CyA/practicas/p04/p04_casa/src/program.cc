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

#include "program.h"

/**
 * @brief Construct a new Program object
 * 
 * @param input_stream 
 * @param name_program 
 */
Program::Program(std::ifstream& input_stream, const std::string& name_program) {
  EvaluateProgram(input_stream, name_program);
}

/**
 * @brief evaluates the file defining the private members
 * 
 * @param input_stream 
 * @param name_program 
 */
void Program::EvaluateProgram(std::ifstream& input_stream, const std::string& name_program) {
  std::stringstream buffer_in;
  buffer_in << input_stream.rdbuf();
  program_ = buffer_in.str();

  name_program_ = name_program;
  variables_.EvaluateFile(program_);
  comments_.EvaluateFile(program_);
  statements_.EvaluateFile(program_);
}

/**
 * @brief write the description
 * 
 * @param out 
 * @return std::ostream& 
 */
void Program::WriteDescription(std::ostream& out) const {
  std::regex description_comment{R"((\/\*\*)[\s\S]*?(Universidad)[\s\S]*?(\*\/))", std::regex::ECMAScript | std::regex::multiline};
  std::smatch matches;
  std::regex_search(program_, matches, description_comment, std::regex_constants::match_continuous);
  out << "DESCRIPTION:\n" << matches.str() << std::endl;
}

/**
 * @brief evaluates if main exist
 * 
 * @param out 
 */
void Program::IsMain(std::ostream& out) const {
  std::regex is_main(R"(int main)", std::regex::ECMAScript|std::regex::multiline);
  out << "MAIN:\n";
  std::regex_search(program_, is_main) ? out << "True\n" : out << "False\n";
}

/**
 * @brief write a program class
 * 
 * @param output_stream 
 * @param programa_out 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& output_stream, const Program& programa_out) {
  output_stream << "PROGRAM: " << programa_out.GetName() << std::endl;
  programa_out.WriteDescription(output_stream);
  output_stream << std::endl;
  output_stream << programa_out.GetVariables() << std::endl;
  output_stream << programa_out.GetStatemens() << std::endl;
  programa_out.IsMain(output_stream);
  output_stream << std::endl;
  output_stream << programa_out.GetComments();
  return output_stream;
}