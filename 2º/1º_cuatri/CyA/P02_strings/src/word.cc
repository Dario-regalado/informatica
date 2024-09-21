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
#include "language.h"


Word::Word(const std::string &input_word){
  if(input_word != "&") word_ = input_word;
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
Language Word::Prefijo(){
  Language lenguaje_return; 
  lenguaje_return.Insert(Word("&"));  //insertamos la cadena vacia 

  for (unsigned i = 1; i <= word_.size(); i++) {
    std::string insert_string = word_.substr(0, i); //substraemos desde la pos 0 hasta i
    lenguaje_return.Insert(insert_string);
  }
  return lenguaje_return;
}

/**
 * @brief calcula los sufijos de la cadena
 * 
 * @return std::set<std::string> 
 */
Language Word::Sufijo(){
  Language lenguaje_return;
  lenguaje_return.Insert(Word("&"));  //insertamos la cadena vacia 
  for (size_t i = 0; i < word_.size(); i++) {
    std::string insert_string = word_.substr(i);  // Extraemos el sufijo desde la posición i hasta el final de la cadena
    lenguaje_return.Insert(insert_string);  // Insertamos el sufijo en el conjunto
  }
  return lenguaje_return;
}



bool operator<(const Word& word_compare1, const Word& word_compare2) {
  if(word_compare1.GetSize() < word_compare2.GetSize()) return true; //si el tamaño de word1 es menor, retorna true
  else if(word_compare1.GetSize() == word_compare2.GetSize()) {
    return word_compare1.GetWord() < word_compare2.GetWord(); // si son igual tamaño, retorna si word1 es menor segun estipulado por std::string
  }
  return false;
}

