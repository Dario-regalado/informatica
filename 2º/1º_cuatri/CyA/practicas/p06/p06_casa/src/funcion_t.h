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
#include "QEstados.h"
#include "FEstados.h"
#include "symbol.h"


class FuncionT {
 public:
  FuncionT() = default;
  FuncionT(const QEstados& estados, const FEstados& finales)
        : conjunto_estados_(estados), conjunto_estados_finales_(finales) {}

  bool FuncTrans(const std::string& input);
  void AgregarTransicion(const Estado& origen, const Symbol& simbolo, const Estado& destino);
  
  //getter

 private:
  bool HayInterseccionConAceptacion(const std::set<Estado>& estados_actuales) const;
  std::multimap<std::pair<Estado, Symbol>, Estado> transicion_;
  QEstados conjunto_estados_;
  FEstados conjunto_estados_finales_;
};