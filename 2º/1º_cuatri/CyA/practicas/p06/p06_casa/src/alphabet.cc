/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief contiene la implementacion de la clase Alphabet,
  *        con la condicion de que un alfabeto no puede estar vacio
  * @Practica 2: Cadenas y lenguajes
  * @bug There are no known bugs
  * @file cya-P02-alphabet.cc
  */

#include "alphabet.h"

/**
 * @brief Construct a new Alphabet object
 * 
 * @param input_alphabet 
 */
Alphabet::Alphabet(const std::string &input_alphabet) {
  //if(input_alphabet != "")
  for (const char &c : input_alphabet) {
    alphabet_.insert(c);  // Insertamos cada carácter en el conjunto
  }
}

/**
 * @brief compureba si una cadena pertenece al alfabeto
 * 
 * @param word_in_alphabet 
 * @return true 
 * @return false 
 */
bool Alphabet::IsInAlphabet(const std::string& word_in_alphabet) {
  for (unsigned i = 0; i < word_in_alphabet.length(); i++) {
    auto final_alphabet = alphabet_.end();
    if (alphabet_.find(word_in_alphabet.at(i)) == final_alphabet) { // si llega al final y no lo ha encontrado, no esta en el alfabeto
      return false;
    }
  }
  return true;
}


/**
 * @brief insert a new alphabet
 * 
 * @param input_stream 
 * @param new_alphabet 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& input_stream, Alphabet& new_alphabet) {
  std::string temp_alphabet;
  input_stream >> temp_alphabet;  //introducimos en temp_alphabet la cadena de entrada
  if (temp_alphabet != "")
    for (unsigned i = 0; i < temp_alphabet.size(); i++) {
      new_alphabet.alphabet_.insert(temp_alphabet[i]); //introducimos en alphabet_ la cadena de entrada
    }
  else {
    std::cerr << "Un alfabeto no puede estar vacio\n";
    new_alphabet.alphabet_.clear();
  }
  return input_stream;
}

/**
 * @brief print the alphabet
 * 
 * @param output_stream 
 * @param output_alphabet 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& output_stream, const Alphabet& output_alphabet) {
  if (output_alphabet.GetSize() == 0) return output_stream;

  output_stream << '{';

  // Obtenemos el iterador del set
  auto alphabet_set = output_alphabet.GetAlphabet();
  auto alphabet_iterator = alphabet_set.begin();
  auto alphabet_end = alphabet_set.end();

  // Verificamos si el conjunto no está vacío
  if (alphabet_iterator != alphabet_end) {
    // Imprimimos el primer elemento sin ", "
    output_stream << *alphabet_iterator++;
  }

  // Imprimimos los elementos restantes con una ", " antes
  while (alphabet_iterator != alphabet_end) {
    output_stream << ", " << *alphabet_iterator++;
  }

  // Cerramos el alfabeto
  output_stream << '}';
  return output_stream;
}
