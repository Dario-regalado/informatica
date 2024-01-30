#include <iostream>

int main() {
  int N_sequence{0};
  int valor1{0};
  int espacio{0};
  while (std::cin >> N_sequence) {
    if (espacio == 0) {
      espacio = 1;
    } else {
      std::cout << std::endl;
    }
    for (int i = 0; i < N_sequence; ++i) {
      for (int j = 0; j < N_sequence; j++) {
        std::cout << valor1;
        valor1++;
        if (valor1 > 9) {
          valor1 = 0;
        }
        
      }
      std::cout << std::endl;
    }
    
  }
  
}
