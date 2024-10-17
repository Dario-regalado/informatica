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
  * @file cya P02 FuncionT_finito
  */

#pragma once
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "estado.h"


class FuncionT {
 public:
  FuncionT() = default;
  FuncionT();

  //getter

 private:
  std::multimap<std::pair<Estado, char>, Estado> transicion_;
};
