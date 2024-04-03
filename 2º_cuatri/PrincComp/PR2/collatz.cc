#include <iostream>

int main() {
  long numero;

  while (true) {
    int secuencias{0};
    double media{0};
    std::cout << "introduce el numero de collatz, escribe 0 para salir: ";
    std::cin >> numero;
    if (numero == 0) {
      break;
    }

    while (numero > 1) {
      if (numero % 2 == 0) {
        numero /= 2;
      } else {
        numero = numero * 3 + 1;
      }

      std::cout << numero << " ";
      secuencias++;
      media += numero;
    }
    std::cout << std::endl;
    std::cout << "valor medio de la secuencia: " << media / secuencias << std::endl;
  }
  return 0;
}