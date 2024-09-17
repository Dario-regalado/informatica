/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Feb 05 2024
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

class RationalT {
 public:
  RationalT(const int = 0, const int = 1);
  ~RationalT() {}
  
  // getters
  int GetNum() const;
  int GetDen() const;
  
  // setters
  void SetNum(const int);
  void SetDen(const int);

  double Value(void) const;

  // FASE II
  bool IsEqual(const RationalT&, const double precision = EPSILON) const;
  bool IsGreater(const RationalT&, const double precision = EPSILON) const;
  bool IsLess(const RationalT&, const double precision = EPSILON) const;
  
  // FASE III
  RationalT Add(const RationalT&);
  RationalT Substract(const RationalT&);
  RationalT Multiply(const RationalT&);
  RationalT Divide(const RationalT&);
  
  void Write(std::ostream& = std::cout) const;
  void Read(std::istream& = std::cin);
  
 private:
  int num_; //Atributos privados de la clase
  int den_; //Atributos privados de la clase
};
