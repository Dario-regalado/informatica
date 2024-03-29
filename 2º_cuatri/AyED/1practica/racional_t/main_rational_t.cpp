/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructura de Datos 2023-2024
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

using namespace std;

int main()
{
  rational_t a(1, 2), b(3), c;

  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  cout << "c.value()= " << c.value() << endl;

  cout << "a: ";
  a.write();
  cout << "b: ";
  b.write();

  c.read();
  cout << "c: ";
  c.write();

  // FASE II
  rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
  cout << "x > y? " << (x.is_greater(y) ? "true" : "false") << endl;
  cout << "x < y? " << (x.is_less(y) ? "true" : "false") << endl;

  // FASE III
  cout << "a + b: ";
  a.add(b).write();
  
  cout << "b - a: ";
  b.substract(a).write();

  cout << "a * b: ";
  a.multiply(b).write();
  
  cout << "a / b: ";
  a.divide(b).write();


  // PRACTICA MODIFICADA
  cout << "a - 1: ";
  a.SubUnity().write();
  
  return 0;
}