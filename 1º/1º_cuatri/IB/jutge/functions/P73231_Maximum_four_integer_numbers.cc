#include <iostream>
#include <algorithm>

int max4(int numero1, int numero2, int numero3, int numero4){
  return std::max(std::max(numero1, numero2), std::max(numero3, numero4));
}

int main() {
  int numero1; int numero2; int numero3; int numero4;
  while (std::cin >> numero1 >> numero2 >> numero3 >> numero4) {
    std::cout << "max(" << numero1 << ", " << numero2 << ", " << numero3<< ", " << numero4<< ") → " << max4(numero1, numero2, numero3, numero4) << std::endl;
  }
  
}