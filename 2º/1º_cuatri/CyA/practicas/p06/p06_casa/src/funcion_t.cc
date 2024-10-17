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


bool FuncionT::FuncTrans(const std::string& input) {

  std::set<Estado> current = {conjunto_estados_.GetInicial()};

  for (char c : input) {
    std::set<Estado> next;
    for (const auto& state : current) {
      // Obtener las transiciones desde el estado actual con el símbolo `c`
      auto range = transicion_.equal_range({state.GetState(), c});
      for (auto it = range.first; it != range.second; ++it) {
        next.insert(it->second);
      }
      // Agregar las transiciones epsilon (`ϵ`)
      auto epsilon_range = transicion_.equal_range({state.GetState(), '&'});
      for (auto it = epsilon_range.first; it != epsilon_range.second; ++it) {
        next.insert(it->second);
      }
    }
    current = next;
  }
  // Verificar si algún estado en `current` es de aceptación
  if (HayInterseccionConAceptacion(current)) 
    return true;
  return false;
    
}

void FuncionT::AgregarTransicion(const Estado& origen, const Symbol& simbolo, const Estado& destino) {
  transicion_.insert({{origen.GetState(), simbolo}, destino});
}


bool FuncionT::HayInterseccionConAceptacion(const std::set<Estado>& estados_actuales) const {
  for (const auto& estado : estados_actuales) {
    int id_state = estado.GetState();
    if (conjunto_estados_finales_.GetFEstados().find(id_state) != conjunto_estados_finales_.GetFEstados().end()) {
      return true;
    }
  }
  return false;
}