/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 
  * @brief 
  * @Practica 
  * @bug There are no known bugs
  * @file cya P02 Estado_finito
  */

#pragma once
#include <iostream>


class Estado {
 public:
  Estado() = default;
  Estado(const int state) : state_{state} {}

  friend std::istream& operator>> (std::istream&, const Estado&);

  //getter
  int GetState() const {return state_;}

 private:
  int state_;
};

bool operator<(const Estado&, const Estado&);
std::ostream& operator<<(std::ostream&, const Estado&);