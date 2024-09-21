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

class Language {
 public:
  Language() = default;
  Language(const Word&);

  std::set<Word> GetLanguage() const {return language_;}
  int GetSize() const {return language_.size();}

  void Insert(const Word&);
  void Insert(const std::string&);
  //friend std::istream& operator>>(std::istream&, Language&);
  
 private:
  std::set<Word> language_;
};

std::ostream& operator<<(std::ostream&, const Language&);