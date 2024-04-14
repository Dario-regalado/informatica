// AUTOR: Dario Regalado Gonzalez
// FECHA: 08 abril 2024
// EMAIL: alu0101640150@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un caracter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      // poner código
      stack_.push(i);
      std::cout << " (es un digito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  // poner código
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');
  
  // poner código
  int a = stack_.top();
  stack_.pop();
  std::cout << "   Sacamos de la pila un operando: " << a << std::endl;

  // poner código
  int b{0}; 
  if (!stack_.empty()) {
    b = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << b << std::endl;
  }

  int resultado;
  switch (c) {
    case '+':
      resultado = a + b;
      break;
    // poner código resto de operadores
    case '-':
      resultado = b - a;
      break;
    case '*':
      resultado = a * b;
      break;
    case '/':
      resultado = b / a;
      break;
    case '^':
      resultado = pow(b,a);
      break;
    case 'r':
      resultado = sqrt(b);
      break;
    case 'l':
      resultado = log(b) / log(2);
      break;
    case 'c':
      resultado = b * b;
      break;
  }

  // poner código
  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
  stack_.push(resultado);
}

 
#endif  // RPNT_H_
