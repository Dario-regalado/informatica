/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief contiene la definicion de la calse Alphabet
  *        mas la sobrecarga de operadores necesaria.
  *        Utiliza un set de Symbol para almacenar el alfabeto
  * @Practica 2: Cadenas y lenguajes
  * @bug There are no known bugs
  * @file cya-P02-alphabet.h
  */

#pragma once
#include <set>
#include <string>
#include <iostream>
#include "symbol.h"
#include "word.h"

class Alphabet {
 public:
  //constructores
  Alphabet() = default;
  Alphabet(const std::string& input_alphabet);

  //getters
  int GetSize() const {return alphabet_.size();}
  std::set<Symbol> GetAlphabet() const {return alphabet_;}

  bool IsInAlphabet(const Word&);
  friend std::istream& operator>>(std::istream&, Alphabet&);

 private:
  std::set<Symbol> alphabet_;
};

std::ostream& operator<<(std::ostream&, const Alphabet&);