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
#include <fstream>
#include <iostream>

class Alphabet {
 public:
  //constructores
  Alphabet() = default;
  Alphabet(const std::string& input_alphabet);

  //getters
  int GetSize() const {return size_;}
  std::set<char> GetAlphabet() const {return alphabet_;}

  friend std::istream& operator>>(std::istream&, Alphabet&);

 private:
  std::set<char> alphabet_;
  int size_;
};

std::ostream& operator<<(std::ostream&, const Alphabet&);