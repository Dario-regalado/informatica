#include <iostream>

void Square(int n) {
  int secuencia{0};
  for (int i = 1; i <= n; i++) {
    secuencia = 0;
    for (size_t j = 1; j < (n * n + 1); j++) {
      std::cout << secuencia;
      ++secuencia;
      if (secuencia == 10) {
        secuencia = 0;
      }
      if ((j) % n == 0) {
        std::cout << std::endl;
      }
    }
    if (i != n) {
      std::cout << std::endl;
    }
  } 
}

int main() {
  int n{0};
  std::cin >> n;
  Square(n);
  return 0;
}