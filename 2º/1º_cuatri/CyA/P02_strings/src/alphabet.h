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
#include <set>
#include <string>
#include <iostream>
#include "symbol.h"

class Alphabet {
 public:
  //constructores
  Alphabet() = default;
  Alphabet(const std::string& input_alphabet);

  //getters
  int GetSize() const {return alphabet_.size();}
  std::set<Symbol> GetAlphabet() const {return alphabet_;}

  friend std::istream& operator>>(std::istream&, Alphabet&);

 private:
  std::set<Symbol> alphabet_;
};

std::ostream& operator<<(std::ostream&, const Alphabet&);