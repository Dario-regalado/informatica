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

#include "symbol.h"

std::ostream& operator<<(std::ostream& stream_out, const Symbol& symbol_out) {
  stream_out << symbol_out.GetSymbol();
  return stream_out;
}

std::istream& operator>>(std::istream& stream_in, Symbol& symbol_in) {
  stream_in >> symbol_in.symbol_;
  return stream_in;
}

bool operator<(const Symbol& simbolo1, const Symbol& simbolo2){
  return (simbolo1.GetSymbol() < simbolo2.GetSymbol());
}