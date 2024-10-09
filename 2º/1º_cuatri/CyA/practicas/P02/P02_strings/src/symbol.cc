/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief contiene la implementacion de la clase Symbol.
  * @Practica 2: Cadenas y lenguajes
  * @bug There are no known bugs
  * @file cya-P02-symbol.cc
  */

#include "symbol.h"

/**
 * @brief operator<< to print a symbol
 * 
 * @param stream_out 
 * @param symbol_out 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& stream_out, const Symbol& symbol_out) {
  stream_out << symbol_out.GetSymbol();
  return stream_out;
}

/**
 * @brief operator>> to insert a new Symbol
 * 
 * @param stream_in 
 * @param symbol_in 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& stream_in, Symbol& symbol_in) {
  stream_in >> symbol_in.symbol_;
  return stream_in;
}

/**
 * @brief compare 2 Symbol by it's ASCII value
 * 
 * @param simbolo1 
 * @param simbolo2 
 * @return true 
 * @return false 
 */
bool operator<(const Symbol& simbolo1, const Symbol& simbolo2){
  return (simbolo1.GetSymbol() < simbolo2.GetSymbol());
}