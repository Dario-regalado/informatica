// AUTOR: Dario Regalado Gonzalez
// FECHA: 4 marzo 2024
// EMAIL: alu0101640150@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  //modificacion
  void WriteConsecutives(const double = EPS) const;

};

// E/S
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < get_size(); i++) {
    if (IsNotZero(at(i))) {
      result += at(i)*pow(x, i);
    }
  }
  
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  int nz1{0};
  for (int i = 0; i < get_size(); i++) {
    if (IsNotZero(at(i)))
    nz1++;
  }
  int nz2{0};
  for (int i = 0; i < pol.get_size(); i++) {
    if (IsNotZero(pol.at(i)))
      nz2++;
  }
  if (nz1 != nz2)
    differents = true;

  for (int i = 0; i < std::min(get_size(), pol.get_size()); i++) {
    if (fabs(at(i) - pol.at(i)) > eps)
      differents = true;
  }
  
  return !differents;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < get_nz(); i++) {
    result += pow(x, at(i).get_inx()) * at(i).get_val();
  }
  
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol,
			                         const double eps) const {
  bool differents = false;
  if ((get_nz() != spol.get_nz())) 
    differents = true;

  for (int i = 0; i < std::min(get_nz(), spol.get_nz()); i++) {
    if (fabs(at(i).get_val() - spol.at(i).get_val()) > eps || at(i).get_inx() != spol.at(i).get_inx())
      differents = true;
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  int nz{0};
  for (int i = 0; i < pol.get_size(); i++) {
    if (IsNotZero(pol.at(i)))
      nz++;
  }
  if (nz != get_nz())
    differents = true;

  nz = 0;
  for (int i = 0; i < std::min(pol.get_size(), get_nz()); i++) {
    if (IsNotZero(pol.at(i))) {
      if (fabs(at(nz).get_val() - pol.at(i)) > eps || at(nz).get_inx() != i) {
          differents = true;
      }
      nz++;
    }
  }
  
  return !differents;
}

// modificacion
void SparsePolynomial::WriteConsecutives(const double) const {
  bool repeticiones = false; // variable para comprobar la repeticion en la impresion de los monomios consecutivos

  for (int i = 1; i < get_nz(); i++) {
    if (at(i - 1).get_inx() != at(i).get_inx() - 1)
      repeticiones = false; // si los indices de los grados son distintos, no hay repeticiones de monomios consecutivos

    // comprobamos los grados consecutivos, e imprimimos
    if (at(i - 1).get_inx() == at(i).get_inx() - 1) {
      if (repeticiones == true) {
        std::cout << at(i).get_val() << ", ";
        repeticiones = 0;
      } else {
        std::cout << at(i - 1).get_val() << ", " << at(i).get_val() << ", ";
        repeticiones = true;
      }
    }
  }
}


#endif  // POLYNOMIAL_H_