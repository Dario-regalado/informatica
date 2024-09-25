/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief contiene la definicion de la calse Language
  *        mas la sobrecarga de operadores necesaria.
  *        se usa un set de Word para almacenar el lenguaje
  * @Practica 2: Cadenas y lenguajes
  * @bug There are no known bugs
  * @file cya-P02-language.h
  */

#pragma once
#include <iostream>
#include <set>
#include <string>
#include "word.h"

class Language {
 public:
  Language() = default;
  Language(const Word&);

  //getters
  std::set<Word> GetLanguage() const {return language_;}
  int GetSize() const {return language_.size();}

  void Insert(const Word&);
  void Insert(const std::string&);

  friend std::istream& operator>>(std::istream&, Language&);
  
 private:
  std::set<Word> language_;
};

std::ostream& operator<<(std::ostream&, const Language&);