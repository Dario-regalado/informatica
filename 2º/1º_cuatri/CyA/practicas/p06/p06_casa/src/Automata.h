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
  * @file cya P02 automata_finito
  */

#pragma once
#include <iostream>
#include <tuple>
#include "alphabet.h"
#include "QEstados.h"
#include "FEstados.h"
#include "estado.h"
#include "funcion_t.h"

class Automata {
 public:
  Automata() = default;
  Automata();

  //getter

 private:
  std::tuple<Alphabet, QEstados, Estado, FEstados, FuncionT> automata_;
};
