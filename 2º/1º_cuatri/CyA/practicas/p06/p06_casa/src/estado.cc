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

#include "estado.h"


/**
 * @brief Construct a new Estado object
 * 
 * @param  
Estado::Estado(const int state) {

}
 */

bool operator== (const Estado& first_st, const Estado& second_st) {
  return first_st.GetState() == second_st.GetState();
}
bool operator< (const Estado& first_st, const Estado& second_st) {
  return first_st.GetState() < second_st.GetState();
}

std::istream& operator>> (std::istream& input, Estado& nuevo_estado) {
  input >> nuevo_estado.state_;
  return input;
}

std::ostream& operator<<(std::ostream& output, const Estado& salida) {
  output << salida.GetState();
  return output;
}