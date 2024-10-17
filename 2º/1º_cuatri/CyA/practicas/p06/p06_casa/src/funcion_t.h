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
#include <stack>
#include "estado.h"
#include "QEstados.h"
#include "FEstados.h"
#include "symbol.h"

typedef std::map<Estado, std::multimap<Symbol, Estado>> f_tran;
class FuncionT {
 public:
  FuncionT() = default;

  bool FuncTrans(const std::string& input, const QEstados&, const FEstados&, const bool);
  void AgregarTransicion(const Estado& origen, const Symbol& simbolo, const Estado& destino);
  
  //getter
  f_tran GetFunc() const {return transicion_;}

 private:
  bool DFATransition(const std::string& input, const QEstados&, const FEstados&);
  bool NFATransition(const std::string& input, const QEstados&, const FEstados&);
  f_tran transicion_;
};