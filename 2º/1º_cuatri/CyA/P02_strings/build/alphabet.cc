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

#include "alphabet.h"

/**
 * @brief Construct a new Alphabet object
 * 
 * @param input_alphabet 
 */
Alphabet::Alphabet(const std::string &input_alphabet) {
  for (int i = 0; i < input_alphabet.size(); i++) {
    alphabet_.insert(input_alphabet[i]);
    size_++;
  }
}

std::ifstream& operator>>(std::ifstream& input_file, Alphabet& new_alphabet) {
  std::string temp_alphabet;
  input_file >> temp_alphabet;
  for (int i = 0; i < temp_alphabet.size(); i++) {
    new_alphabet.alphabet_.insert(temp_alphabet[i]);
  }
}


std::ofstream& operator<<(std::ofstream& output_file, const Alphabet& output_alphabet){
  output_file << '{';

  // creamos un indice iterador del set
  auto alphabet_iterator{output_alphabet.GetAlphabet().begin()};
  //imprimimos el primer elemento
  output_file << *alphabet_iterator++;

  //mientras el iterador no llegue al fin, imprimimos
  while (alphabet_iterator != output_alphabet.GetAlphabet().end()) {
    output_file << ", " << *alphabet_iterator++;
  }
  
  //cerramos el alfabeto
  output_file << '}';
  return output_file;  
}

std::ostream& operator<<(std::ostream& output_stream, const Alphabet& output_alphabet){
  output_stream << '{';

  // creamos un indice iterador del set
  auto alphabet_iterator{output_alphabet.GetAlphabet().begin()};
  //imprimimos el primer elemento
  output_stream << *alphabet_iterator++;

  //mientras el iterador no llegue al fin, imprimimos
  while (alphabet_iterator != output_alphabet.GetAlphabet().end()) {
    output_stream << ", " << *alphabet_iterator++;
  }
  
  //cerramos el alfabeto
  output_stream << '}';
  return output_stream;  
}