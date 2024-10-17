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

typedef std::set<Estado> q_estados;

class QEstados {
 public:
  QEstados() = default;
  QEstados(const Estado&);

  void Insert(const Estado&);
  void Clear();
  //getter
  q_estados GetQEstado() const {return conjunto_estados_;}
  Estado GetInicial() const;

 private:
  q_estados conjunto_estados_;
  int key_;
};

std::ostream& operator<<(std::ostream&, const QEstados&);
