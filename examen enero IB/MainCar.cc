#include <iostream>
#include "Car.h"

int main() {
  Car coche1, coche2;
  std::cin >> coche1 >> coche2;
  bool temp{coche1 < coche2};
  std::cout << temp << std::endl;
  return 0;
}