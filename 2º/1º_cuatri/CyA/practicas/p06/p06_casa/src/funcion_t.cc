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

#include "funcion_t.h"

bool FuncionT::FuncTrans(const std::string& input, const QEstados& q_estados, const FEstados& f_estados, const bool is_dfa) {
  if(is_dfa)
    return (DFATransition(input, q_estados, f_estados));
  return NFATransition(input, q_estados, f_estados);
}


bool FuncionT::DFATransition(const std::string& input, const QEstados& q_estados, const FEstados& f_estados) {
  Estado inicial = q_estados.GetInicial();
  //para mayor simplicidad en el codigo, usaremos un set de int en vez de QEstados
  std::set<int> current = {inicial.GetState()}; 
  for(char simbol : input) {
    std::set<int> next;
    for (auto estado : current) {
      for (auto tr : transicion_[estado]) {
        if(simbol == tr.first || simbol == '&')
          next.insert(tr.second.GetState());
      }
    }
    current = next;
  }

  auto fin_estados = f_estados.GetFEstados();
  for(auto final_state : current) {
    if(fin_estados.find((final_state)) == fin_estados.end())
      return false;
  }
  return true;
}

bool FuncionT::NFATransition(const std::string& input, const QEstados& q_estados, const FEstados& f_estados) {
  Estado inicial = q_estados.GetInicial();
  //para mayor simplicidad en el codigo, usaremos un set de int en vez de QEstados
  std::set<int> temp = {inicial.GetState()}; 
  std::set<std::set<int>> current = {temp};
  for(char simbol : input) {
    std::set<int> next;
    for (auto set : current) {
      for (auto estado : set) {
        for (auto tr : transicion_[estado]) {
          if(simbol == tr.first || simbol == '&')
            next.insert(tr.second.GetState());
        }
      }
    }
    current.insert(next);
  }

  auto fin_estados = f_estados.GetFEstados();
  for(auto set : current) {
    for(auto final_state : set)
      if(fin_estados.find((final_state)) == fin_estados.end())
        return false;
  }
  return true;
}


void FuncionT::AgregarTransicion(const Estado& origen, const Symbol& simbolo, const Estado& destino) {
  transicion_[origen].insert(std::make_pair(simbolo, destino));
}