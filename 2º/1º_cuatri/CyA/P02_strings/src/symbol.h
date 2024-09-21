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

#pragma once
#include <iostream>

class Symbol {
 public:
  Symbol() = default;
  Symbol(const char c) : symbol_{c} {}

  friend std::istream& operator>>(std::istream&, Symbol&);

  char GetSymbol() const {return symbol_;}
 private:
  char symbol_;
};

std::ostream& operator<< (std::ostream&, const Symbol&);
bool operator<(const Symbol&, const Symbol&);