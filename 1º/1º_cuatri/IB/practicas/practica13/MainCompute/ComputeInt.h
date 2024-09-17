/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 13 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#pragma once

class ComputeInt {
 public:
  ComputeInt(const int numero_1, const int numero_2) : primer_numero_{numero_1}, segundo_numero_{numero_2} {}
  int Factorial() const;
  int SumSerie() const;
  bool IsPrime() const;
  bool IsPerfect() const;
  bool AreRelativePrimer() const;

 private:
  int primer_numero_{0};
  int segundo_numero_{0};
};
