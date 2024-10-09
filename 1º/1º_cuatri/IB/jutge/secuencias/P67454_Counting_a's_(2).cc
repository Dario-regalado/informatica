#include <iostream>
#include <string>

int main() {
  std::string palabra{""};
  getline(std::cin, palabra);
  int secuencia_de_a{0};
  for (auto& element : palabra) {
    if (element == '.') {
      break;
    }
    if (element == 'a') {
      ++secuencia_de_a;
    }
  }
  std::cout << secuencia_de_a << std::endl;
}