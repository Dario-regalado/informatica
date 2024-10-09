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

#pragma once
#include <cmath>
#include <iostream>

class Esfera {
 public:
  Esfera(const double radio, const double masa) : radio_{radio}, masa_{masa} {} // Constructor de la clase
  double AreaSuperficial();
  double Volumen();
  double Densidad();

 private:
  double radio_{0.0};
  double masa_{0.0};
};