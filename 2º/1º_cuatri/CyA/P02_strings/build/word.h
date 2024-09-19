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
#include <fstream>

class Word {
 public:
  Word() = default;
  Word(const std::string &input_word) : word_{input_word} {}

  std::string GetWord() const {return word_;}
  int GetSize() const {return word_.size();}
  std::string Reverse() const;
  friend std::ifstream& operator>>(std::ifstream&, Word&);

 private:
  std::string word_;
};

std::ofstream& operator<<(std::ofstream&, const Word&);
std::ostream& operator<<(std::ostream&, const Word&);