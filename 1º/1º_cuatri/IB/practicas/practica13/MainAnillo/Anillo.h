/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 21 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#ifndef ANILLO_H
#define ANILLO_H

#include <iostream>

class Anillo {
 public:
 /**
  * @brief Construct a new Anillo object
  * 
  * @param radio_interior 
  * @param radio_exterior 
  */
  Anillo(const int radio_interior, const int radio_exterior) : radio_interior_{radio_interior}, radio_exterior_{radio_exterior} {}
  
  /**
   * @brief Construct a new Anillo object
   * 
   */
  Anillo() = default;
  /**
   * @brief Get the Radio Interior object
   * 
   * @return int 
   */
  int GetRadioInterior() const {return radio_interior_;}
  /**
   * @brief 
   * 
   * @return int 
   */
  int GetRadioExterior() const {return radio_exterior_;}

  friend std::istream& operator>>(std::istream& in, Anillo& nuevo_anillo);

 private:
  int radio_interior_{0};
  int radio_exterior_{0};
};

std::ostream& operator<<(std::ostream& out, const Anillo& salida_anillo);
Anillo operator*(const Anillo& anillo_1, const int numero_multiplicador);
Anillo operator+(const Anillo& anillo_1, const Anillo& anillo_sumador);
Anillo operator+(const Anillo& anillo_1, const int numero);

#endif