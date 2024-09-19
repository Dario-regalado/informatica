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

#include "clase.h"

/**
 * @brief Construct a new Language:: Language object
 * 
 * @param input_chain 
 * @param input_alphabet_ 
 */
/////////////// subceptible a cambios
Language::Language(const std::string &input_chain, const std::string &input_alphabet) {
  chain_ = input_chain;
  for(const auto &element : input_alphabet) {
    alphabet_.insert(element);
  }
}

std::string Language::Alfabeto() const {
  std::string alfabeto_retorno;

  auto iterator = alphabet_.begin();
  alfabeto_retorno += '{' + *iterator;
  for(auto i = iterator; iterator != alphabet_.end(); ++i) {
    alfabeto_retorno += ", " + *i;
  }
  alfabeto_retorno += '}';
}