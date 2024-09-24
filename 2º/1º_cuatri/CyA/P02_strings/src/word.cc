/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief contiene la implementacion de la clase Word e
  *        utiliza la clase Language de manera especial, 
  *        ya que Sufijo y Prefijo retornan un Language
  * @Practica 2: Cadenas y lenguajes
  * @bug There are no known bugs
  * @file cya-P02-word.cc
  */

#include "word.h"
#include "language.h"

/**
 * @brief Construct a new Word:: Word object
 * 
 * @param input_word 
 */
Word::Word(const std::string &input_word){
  word_ = input_word;
  //if(word_ == "&") word_.clear();
}


/**
 * @brief operator>> overloaded as a friend funcion
 * 
 * @param input_stream 
 * @param input_word 
 * @return std::ifstream& 
 */
std::istream& operator>>(std::istream& input_stream, Word& input_word) {
  input_stream >> input_word.word_;
  if(input_word.word_ == "&") input_word.word_.clear();
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
 * @brief invierte la cadena
 * 
 * @return Word 
 */
Word Word::Reverse() const {
  std::string reverse_string;
  reverse_string.reserve(GetLenght()); //reservamos el tamaño
  for (int i = GetLenght() - 1; i >= 0; i--) {
    reverse_string += word_[i];
  }
  return Word(reverse_string);
}

/**
 * @brief calcula los prefijos de la cadena
 * 
 * @return Language
 */
Language Word::Prefijo(){
  Language lenguaje_return; 
  lenguaje_return.Insert(std::string("&"));  //insertamos la cadena vacia 

  for (unsigned i = 1; i <= word_.size(); i++) {
    std::string insert_string = word_.substr(0, i); //substraemos desde la pos 0 hasta i
    lenguaje_return.Insert(insert_string);
  }
  return lenguaje_return;
}

/**
 * @brief calcula los sufijos de la cadena
 * 
 * @return Language 
 */
Language Word::Sufijo(){
  Language lenguaje_return;
  lenguaje_return.Insert(std::string("&"));  //insertamos la cadena vacia 
  for (size_t i = 0; i < word_.size(); i++) {
    std::string insert_string = word_.substr(i);  // Extraemos el sufijo desde la posición i hasta el final de la cadena
    lenguaje_return.Insert(insert_string);  // Insertamos el sufijo en el conjunto
  }
  return lenguaje_return;
}


/**
 * @brief compara la longitud de dos cadenas y/o que cadena tiene menor valor ASCII
 * 
 * @param word_compare1 
 * @param word_compare2 
 * @return true 
 * @return false 
 */
bool operator<(const Word& word_compare1, const Word& word_compare2) {
  if(word_compare1.GetLenght() < word_compare2.GetLenght()) return true; //si el tamaño de word1 es menor, retorna true
  else if(word_compare1.GetLenght() == word_compare2.GetLenght()) {
    return word_compare1.GetWord() < word_compare2.GetWord(); // si son igual tamaño, retorna si word1 es menor segun estipulado por std::string
  }
  return false;
}

