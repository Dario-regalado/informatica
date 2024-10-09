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

#include <iostream>
#include <cmath>

#include "rational_t.hpp"

int main() {
  RationalT a(1, 2), b(3), c;

  std::cout << "a.Value()= " << a.Value() << std::endl;
  std::cout << "b.Value()= " << b.Value() << std::endl;
  std::cout << "c.Value()= " << c.Value() << std::endl;

  std::cout << "a: ";
  a.Write();
  std::cout << "b: ";
  b.Write();

  c.Read();
  std::cout << "c: ";
  c.Write();

  // FASE II
  RationalT x(1, 3), y(2, 3);
  x.Write();
  y.Write();
  std::cout << "x == y? " << (x.IsEqual(y) ? "true" : "false") << std::endl;
  std::cout << "x > y? " << (x.IsGreater(y) ? "true" : "false") << std::endl;
  std::cout << "x < y? " << (x.IsLess(y) ? "true" : "false") << std::endl;

  // FASE III
  std::cout << "a + b: ";
  a.Add(b).Write();

  std::cout << "b - a: ";
  b.Substract(a).Write();
  std::cout << "a * b: ";
  a.Multiply(b).Write();

  std::cout << "a / b: ";
  a.Divide(b).Write();
  
  return 0;
}
