/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief 
  * @bug There are no known bugs
  * @file 
  */

#include "word.h"

/**
 * @brief operator>> overloaded as a friend funcio
 * 
 * @param input_file 
 * @param input_word 
 * @return std::ifstream& 
 */
std::ifstream& operator>>(std::ifstream& input_file, Word& input_word) {
  input_file >> input_word.word_;
  return input_file;
}

/**
 * @brief operator << overloaded
 * 
 * @param file_out 
 * @param word_out 
 * @return std::ofstream& 
 */
std::ofstream& operator<<(std::ofstream& file_out, const Word& word_out){
  file_out << word_out.GetWord();
  return file_out;
}

std::ostream& operator<<(std::ostream& stream_out, const Word& word_out){
  stream_out << word_out.GetWord();
  return stream_out;
}

std::string Word::Reverse() const {
  std::string reverse_string{0};
  for (int i = GetSize() - 1; i >= 0; i--){
    reverse_string += word_[i];
  }
  return reverse_string;
}