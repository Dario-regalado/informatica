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
#include <fstream>
#include <set>
#include "word.h"
#include "alphabet.h"

class Language {
 public:
  Language() = default;
  Language(const Word&);

  Language Sufijo(const Word&);
  Language Prefijo(const Word&);

  std::set<Word> GetLanguage() const {return language_;}
  int GetSize() const {return language_.size();}

  friend std::ifstream& operator>>(std::ifstream&, Language&);
  
 private:
  std::set<Word> language_;
};

std::ofstream& operator<<(std::ofstream&, const Language&);
std::ostream& operator<<(std::ostream&, const Language&);