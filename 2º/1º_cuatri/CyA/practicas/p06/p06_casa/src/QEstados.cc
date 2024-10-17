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

#include "QEstados.h"


/**
 * @brief Construct a new QEstados object
 * 
 * @param  
 */
QEstados::QEstados(const Estado& initial_state) {
  Insert(initial_state);
}

Estado QEstados::GetInicial() const {
  return *conjunto_estados_.begin();
}


void QEstados::Insert(const Estado& nuevo_estado) {
  conjunto_estados_.insert(nuevo_estado);
}


void QEstados::Clear(){
  conjunto_estados_.clear();
}


std::ostream& operator<<(std::ostream& output, const QEstados& conjunto_salida) {
  output << "{";
  const auto& estados = conjunto_salida.GetQEstado();
  for (auto it = estados.begin(); it != estados.end(); it++){
    output << it->GetState();
    if(std::next(it) != estados.end()) {
      output << ", ";
    }
  }
  output << "}";
  return output;
}