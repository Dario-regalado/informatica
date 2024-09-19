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

#include "language.h"

Language::Language(const Word& new_word) {
  language_.insert(new_word);
}

Language Language::Prefijo(const Word& pre_word)  {
  std::string temp_string{"&"};
  language_.insert(temp_string);
  temp_string.erase();
  for (int i = 0; i < pre_word.GetSize(); i++){
    for (int j = 0; j <= i; j++)
    {
      temp_string += pre_word.GetWord()[i];
    }
    language_.insert(temp_string);
    temp_string.erase();
  }
}

// std::ifstream& operator>>(std::ifstream&, Language&) {}


std::ofstream& operator<<(std::ofstream& file_out, const Language& language_out) {
  //abrimos el conjunto
  file_out << "{";

  // creamos un indice iterador del set
  auto language_iterator{language_out.GetLanguage().begin()};
  //imprimimos el primer elemento
  file_out << *language_iterator++;
  //mientras el iterador no llegue al fin, imprimimos
  while (language_iterator != language_out.GetLanguage().end()) {
    file_out << ", " << *language_iterator++;
  }
  //cerramos el conjunto
  file_out << '}';
  return file_out;
}


std::ostream& operator<<(std::ostream& out_stream, const Language& language_out){
  //abrimos el conjunto
  out_stream << "{";

  // creamos un indice iterador del set
  auto language_iterator{language_out.GetLanguage().begin()};
  //imprimimos el primer elemento
  out_stream << *language_iterator++;
  //mientras el iterador no llegue al fin, imprimimos
  while (language_iterator != language_out.GetLanguage().end()) {
    out_stream << ", " << *language_iterator++;
  }
  //cerramos el conjunto
  out_stream << '}';
  return out_stream;
}

