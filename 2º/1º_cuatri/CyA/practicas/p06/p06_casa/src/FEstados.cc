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

#include "FEstados.h"
#include "QEstados.h"


/**
 * @brief Construct a new FEstados object
 * 
 * @param  
 */
FEstados::FEstados(const Estado& inicial) {
  key_ = 0;
  Insert(inicial);
}

void FEstados::Insert(const Estado& estado) {
  conjunto_estados_finales_.insert(std::make_pair(estado.GetState(), estado));
}


void FEstados::Clear(){
conjunto_estados_finales_.clear();
}

bool FEstados::FPerteneceQ(const QEstados& estados_q) {
  const auto& estados_q_map = estados_q.GetQEstado();
  for (const auto& pair : conjunto_estados_finales_) {
    int id_estado = pair.first; // id del estado de FEstados
    if (estados_q_map.find(id_estado) == estados_q_map.end()) {
      return false; //si no encontró un estado de FEstados en QEstados, retorna false
    }
  }
  std::cout << std::endl;
  return true;
}


std::ostream& operator<<(std::ostream& output, const FEstados& conjunto_salida) {
  output << "{";
  const auto& estados = conjunto_salida.GetFEstados();
  for (auto it = estados.begin(); it != estados.end(); it++){
    output << it->second;
    if(std::next(it) != estados.end()) {
      output << ", ";
    }
  }
  output << "}";
  return output;
}