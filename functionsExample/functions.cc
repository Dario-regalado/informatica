  /**
    * Universidad de La Laguna
    * Escuela Superior de Ingeniería y Tecnología
    * Grado en Ingeniería Informática
    * Informática Básica 2023-2024
    *
    * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es 
    * @date Nov 06 2023
    * @brief calculates a function
    * @bug There are no known bugs
    * @see
    */

#include "functions.h"
#include <cmath>

double Function3Variables(double numero1, double numero2, double numero3) {
  double numerador{std::sqrt(2 * numero3 -4)};
  double denominador{numero1 * numero1 - numero2 * numero2};
  double resultado{numerador / denominador};
  return resultado;
}
