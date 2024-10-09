/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief contiene la implementacion de la clase Language
  * @Practica 2: Cadenas y lenguajes
  * @bug There are no known bugs
  * @file cya-P02-language.cc
  */

#include "language.h"

/**
 * @brief Construct a new Language object
 * 
 * @param new_word 
 */
Language::Language(const Word& new_word){
  language_.insert(new_word);
}

/**
 * @brief operator>> to insert a new language
 * 
 * @param input_stream 
 * @param language_new 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& input_stream, Language& language_new) {
  Word temp_word;
  while(input_stream >> temp_word)
    language_new.Insert(temp_word);
  return input_stream;
}

/**
 * @brief operator << to print a language
 * 
 * @param out_stream 
 * @param language_out 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out_stream, const Language& language_out){
  out_stream << '{';

  // Obtenemos el iterador del set
  auto alphabet_set = language_out.GetLanguage();
  auto alphabet_iterator = alphabet_set.begin();
  auto alphabet_end = alphabet_set.end();

  // Verificamos si el conjunto no está vacío
  if (alphabet_iterator != alphabet_end) {
    // Imprimimos el primer elemento sin coma
    out_stream << *alphabet_iterator++;
  }

  // Imprimimos los elementos restantes con una coma antes
  while (alphabet_iterator != alphabet_end) {
    out_stream << ", " << *alphabet_iterator++;
  }

  // Cerramos el alfabeto
  out_stream << '}';
  return out_stream;
}

/**
 * @brief inserta una cadena tipo Word
 * 
 * @param insert_word 
 */
void Language::Insert(const Word& insert_word) {
  language_.insert(insert_word);
}

/**
 * @brief inserta una cadena tipo string
 * 
 * @param insert_word 
 */
void Language::Insert(const std::string& insert_word) {
  language_.insert(Word(insert_word));
}