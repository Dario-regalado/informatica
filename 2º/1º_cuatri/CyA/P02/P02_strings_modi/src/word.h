/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief contiene la definicion de la calse word(cadena)
  *        mas la sobrecarga de operadores necesaria
  * @Practica 2: Cadenas y lenguajes
  * @bug There are no known bugs
  * @file cya-P02-word.h 
  */

#pragma once
#include <string>
#include <iostream>
#include <set>

class Language;

class Word {
 public:
  // constuctors
  Word() = default;
  Word(const std::string&);

  // getters
  std::string GetWord() const {return word_;}
  int GetLenght() const {return word_.size();}

  Word Reverse() const;
  Language Sufijo();
  Language Prefijo();
  Word Potencia(const int);

  friend std::istream& operator>>(std::istream&, Word&);

 private:
  std::string word_;
};

std::ostream& operator<<(std::ostream&, const Word&);
bool operator<(const Word&, const Word&);
Word operator+(const Word&, const Word&);