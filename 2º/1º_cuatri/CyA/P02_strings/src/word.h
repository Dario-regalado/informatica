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
#include <string>
#include <iostream>
#include <fstream>
#include <set>

class Language;

class Word {
 public:
  // constuctors
  Word() = default;
  Word(const std::string&);

  // getters
  std::string GetWord() const {return word_;}
  int GetSize() const {return word_.size();}

  std::string Reverse() const;
  Language Sufijo();
  Language Prefijo();

  friend std::istream& operator>>(std::istream&, Word&);

 private:
  std::string word_;
};

std::ostream& operator<<(std::ostream&, const Word&);
bool operator<(const Word&, const Word&);