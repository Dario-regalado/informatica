/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 12 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "funciones.h"
 
double RaizCuadrada(int number, int number2) {
  constexpr double epsilon{1e-4};
  double delta{1.0};
  double root{1.0};

  while (fabs(root * root - number) > epsilon) {
    if (delta > 0) {
      while (root * root < number) {
        root += delta;
      }
    } else {
      while (root * root > number) {
        root += delta;
      }
    }
    delta *= -0.5;
  }
  //root = sqrt(number2 * number2 + number * number);
  return root;
}
