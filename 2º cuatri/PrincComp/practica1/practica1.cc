/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Feb 14 2024
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include <iostream>

int main() {
  int x;
  bool es_primo = true;

  do {
    std::cout << "Introduce un numero primo: ";
    std::cin >> x;
    for (int i = 2; i < x; ++i) {
      es_primo =(x % i != 0);
      if (!es_primo)
        break;
    } 
  } while (es_primo == false);
  std::cout << "Correcto. El numero introducido es primo.\n";
  return 0;
}
