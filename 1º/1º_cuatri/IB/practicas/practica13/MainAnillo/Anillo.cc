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

#include "Anillo.h"
/**
 * @brief 
 * 
 * @param anillo_1 
 * @param numero_multiplicador 
 * @return Anillo 
 */
Anillo operator*(const Anillo& anillo_1, const int numero_multiplicador) {
  return Anillo{anillo_1.GetRadioInterior() * numero_multiplicador, anillo_1.GetRadioExterior() * numero_multiplicador};
}
/**
 * @brief 
 * 
 * @param in 
 * @param nuevo_anillo 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& in, Anillo& nuevo_anillo) {
  in >> nuevo_anillo.radio_interior_ >> nuevo_anillo.radio_exterior_;
  return in;
}
/**
 * @brief 
 * 
 * @param out 
 * @param salida_anillo 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Anillo& salida_anillo) {
  out << salida_anillo.GetRadioInterior() << " " << salida_anillo.GetRadioExterior();
  return out;
}
/**
 * @brief 
 * 
 * @param anillo_1 
 * @param anillo_sumador 
 * @return Anillo 
 */
Anillo operator+(const Anillo& anillo_1, const Anillo& anillo_sumador) {
  return Anillo{anillo_1.GetRadioInterior() + anillo_sumador.GetRadioInterior(), anillo_1.GetRadioExterior() + anillo_sumador.GetRadioExterior()};
}
/**
 * @brief 
 * 
 * @param anillo_1 
 * @param numero 
 * @return Anillo 
 */
Anillo operator+(const Anillo& anillo_1, const int numero) {
  return Anillo{anillo_1.GetRadioInterior() + numero, anillo_1.GetRadioExterior() + numero};
}