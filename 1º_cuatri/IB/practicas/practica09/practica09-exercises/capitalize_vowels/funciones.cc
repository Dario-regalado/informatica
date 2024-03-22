/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 12 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "funciones.h"

string CapitalizeVowels(const string& imput_word) {
  string output_word{};
  for (int i{0}; i < imput_word.length(); ++i) {
    tolower(imput_word[i]);
    if (imput_word[i] == 'a' || imput_word[i] == 'e' || imput_word[i] == 'i' || imput_word[i] == 'o' || imput_word[i] == 'u') {
      output_word += toupper(imput_word[i]);
    } else {
      output_word += imput_word[i];
    }
  }
  return output_word;
}