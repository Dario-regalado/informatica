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
#include <set>
#include "estado.h"
#include "QEstados.h"

typedef std::set<Estado> f_estados;

class FEstados {
 public:
  FEstados() = default;
  FEstados(const Estado&);

  void Insert(const Estado&);
  void Clear();
  bool FPerteneceQ(const QEstados&);

  //getter
  f_estados GetFEstados() const {return conjunto_estados_finales_;}

 private:
  f_estados conjunto_estados_finales_;
  int key_;
};

std::ostream& operator<<(std::ostream&, const FEstados&);
