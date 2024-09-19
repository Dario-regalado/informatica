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
#include <fstream>
#include <iostream>
#include <string>

class Language {
 public:
  Language(const std::string &input_chain, const std::string& input_alphabet);
  Language() = default;
  std::string Alfabeto() const;
  std::string Longitud() const;
  std::string Inversa() const;
  std::string Prefijos() const;
  std::string Sufijos() const;
  
 private:
  std::set<char> alphabet_;
  std::string chain_;
};