#include <iostream>
#include <cmath>

int LogBase(int base, int argumento) {
  double result{log10(argumento) / log10(base)};
  return result;
}

int main() {
  int base_logaritmo{0};
  int argumento_logaritmo{0};

  while (std::cin >> base_logaritmo >> argumento_logaritmo) {
    if (base_logaritmo < 2 || argumento_logaritmo < 1) {
      return 1;
    }
    std::cout << LogBase(base_logaritmo, argumento_logaritmo) << std::endl;
  }
  return 0;
}