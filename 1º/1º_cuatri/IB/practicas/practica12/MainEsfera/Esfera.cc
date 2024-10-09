/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 14 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "Esfera.h"

/**
 * @brief Calcula el area superficial de la esfera
 * 
 * @return double 
 */
double Esfera::AreaSuperficial() {
  return 4 * M_PI * radio_ * radio_;
}

/**
 * @brief Calcula el volumen de la esfera
 * 
 * @return double 
 */
double Esfera::Volumen() {
  return (4 * M_PI * radio_ * radio_ * radio_) / 3;
}

/**
 * @brief Calcula la densidad de la esfera
 * 
 * @return double 
 */
double Esfera::Densidad() {
  return masa_ / Volumen();
}