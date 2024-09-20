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
 * @brief operator>> overloaded as a friend funcion
 * 
 * @param input_stream 
 * @param input_word 
 * @return std::ifstream& 
 */
std::istream& operator>>(std::istream& input_stream, Word& input_word) {
  input_stream >> input_word.word_;
  return input_stream;
}

/**
 * @brief print the word 
 * 
 * @param stream_out 
 * @param word_out 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& stream_out, const Word& word_out){
  stream_out << word_out.GetWord();
  return stream_out;
}

/**
 * @brief print Sufijo and Prefijo
 * 
 * @param output_stream 
 * @param output_set 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& output_stream, const std::set<std::string>& output_set){
  output_stream << '{';

  // Obtenemos el iterador del set
  auto alphabet_set = output_set;
  auto alphabet_iterator = alphabet_set.begin();
  auto alphabet_end = alphabet_set.end();

  // Verificamos si el conjunto no está vacío
  if (alphabet_iterator != alphabet_end) {
    // Imprimimos el primer elemento sin coma
    output_stream << *alphabet_iterator++;
  }

  // Imprimimos los elementos restantes con una coma antes
  while (alphabet_iterator != alphabet_end) {
    output_stream << ", " << *alphabet_iterator++;
  }

  // Cerramos el alfabeto
  output_stream << '}';
  return output_stream;
}

/**
 * @brief invierte la cadena
 * 
 * @return std::string 
 */
std::string Word::Reverse() const {
  std::string reverse_string;
  reverse_string.reserve(GetSize()); //reservamos el tamaño
  for (int i = GetSize() - 1; i >= 0; i--) {
    reverse_string += word_[i];
  }
  return reverse_string;
}

/**
 * @brief calcula los prefijos de la cadena
 * 
 * @return std::set<std::string> 
 */
std::set<std::string> Word::Prefijo() const {
  std::set<std::string> set_return;
  set_return.insert("&"); //insertamos la cadena vacia
  std::string insert_string;

  for (unsigned i = 0; i < word_.size(); i++) {
    insert_string += word_[i]; //acumulamos en insert_string los prefijos hasta la cadena
    set_return.insert(insert_string);
  }
  return set_return;
}

/**
 * @brief calcula los sufijos de la cadena
 * 
 * @return std::set<std::string> 
 */
std::set<std::string> Word::Sufijo() const {
  std::set<std::string> set_return;
  set_return.insert("&"); //insertamos la cadena vacia
  std::string insert_string;

  for (std::string::size_type i = 0; i < word_.size(); i++) {
    std::string insert_string = word_.substr(i);  // Extraemos el sufijo desde la posición i
    set_return.insert(insert_string);  // Insertamos el sufijo en el conjunto
  }
  return set_return;
}