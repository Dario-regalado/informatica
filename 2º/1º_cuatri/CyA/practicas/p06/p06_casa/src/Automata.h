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
#include <fstream>
#include <string>
#include <sstream>
#include "alphabet.h"
#include "QEstados.h"
#include "FEstados.h"
#include "estado.h"
#include "funcion_t.h"

class Automata {
 public:
  Automata() = default;
  Automata(std::ifstream&);

  void AnalizeAutomata(std::ifstream&);
  bool AnalizeWords(const std::string&);
  //getter

 private:
  Alphabet alfabeto_;
  QEstados q_estados_;
  FEstados f_esstados_;
  Estado inicial_estado;
  FuncionT funcion_transicion_;
  int n_estados_;
  bool is_dfa_;
};
