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

#include <vector>
#include "ComputeInt.h"

int ComputeInt::Factorial() const{
  int temp = primer_numero_;
  for (int i = temp - 1; i > 0; --i){
    temp *= i;
  }
  return temp;
}

int ComputeInt::SumSerie() const{
  int temp{0};
  for (int i = 1; i <= primer_numero_; i++) {
    temp += i;
  }
  return temp;
}

bool ComputeInt::IsPrime() const{
  int temp{primer_numero_};
  int secuencias{0};
  for (int i = 1; i <= temp; i++) {
    if (temp % i == 0) {
      ++secuencias;
    }
  }
  return secuencias == 2;
}

bool ComputeInt::IsPerfect() const{
  int temp{primer_numero_};
  std::vector<int> divisores;
  for (int i = 1; i < temp; i++) {
    if (temp % i == 0) {
      divisores.emplace_back(i);
    }
  }
  int final_number;
  for (int i = 0; i < divisores.size(); i++) {
    final_number += divisores[i];
  }
  return final_number == temp;
}

bool ComputeInt::AreRelativePrimer() const{
  int temp{primer_numero_};
  int secuencias1{0};
  for (int i = 1; i <= temp; i++) {
    if (temp % i == 0) {
    ++secuencias1;
    }
  }
  int temp2{segundo_numero_};
  int secuencias2{0};
  for (int i = 1; i <= temp2; i++) {
    if (temp2 % i == 0) {
    ++secuencias2;
    }
  }
  return secuencias1 == 2 && secuencias2 == 2;
}