/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <cmath>

int main() {
  int n = 10;
  int A[n] = {1, 2,3,4,5,6,7,8,9,10};
  int multiplos_de_tres{0};
  int *indice = new int[n];
  int *no_multiplos = new int[n];

  for (int i = 0; i < n; ++i) {
    if (A[i] % 3 == 0){
      indice[multiplos_de_tres] = i;
      multiplos_de_tres++;
    } else {
      no_multiplos[n - multiplos_de_tres] = i;
    }
  }
  std::cout << "Hay: " << multiplos_de_tres << " elementos multiplo de 3\n";
  std::cout << "Hay: " << n - multiplos_de_tres << " elementos no multiplo de 3\n";
  for (int i = 0; i < multiplos_de_tres; i++) {
    std::cout << indice[i] << " ";
  }

//calcula el modulo del vector no multiplos
  int modulo=0;
  for (int i = 0; i < n; i++)  {
    modulo += no_multiplos[i] * no_multiplos[i];
  }
  modulo = sqrt(modulo);


  delete[] indice;
  delete[] no_multiplos;
  return 0;
}
