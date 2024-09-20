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



void Language::Prefijo(const Word& pre_word)  {  
  std::string temp_string;
  // Generar los prefijos de la palabra
  for (int i = 0; i < pre_word.GetSize(); ++i) {
    temp_string += pre_word.GetWord()[i];  // Agregar el siguiente carácter al prefijo
    language_.insert(temp_string);  // Insertar el prefijo en el lenguaje
  }

}


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

