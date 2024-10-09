#include <iostream>
#include "Box.h"

int main() {
  Box caja1{}, caja2{};
  std::cin >> caja1 >> caja2;
  std::string son_iguales{};
  if (caja1 == caja2){
    son_iguales = "son iguales";
  } else {
    son_iguales = "no son iguales";
  }
  std::cout << "la caja1: " << caja1 << "y la caja2: " << caja2 << son_iguales;
}