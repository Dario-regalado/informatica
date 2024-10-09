/**  
  * Universida de La Laguna
  * Escuela superior de Ingenieria y tecnologia
  * Grado de ingernieria Informatica
  * Infomatica basica 2023-2024
  * 
  * @brief
  * @date
  * @author   
  */

#include <iostream>
#include <vector>

int main() {
  int secuencia{0}, iterations{0};
  while (std::cin >> secuencia) {
    std::vector<int> vector_iterarions{};
    while (std::cin >> iterations) {
      if (iterations == -1) {
        break;
      }
      vector_iterarions.emplace_back(iterations);
    }
    if (secuencia <= vector_iterarions.size()) {
      std::cout << "At the position " << secuencia << "there is a(n) " << vector_iterarions[secuencia - 1] << "." << std::endl;
    } else {
      std::cout << "Incorrect position.\n";
    }
  }
}