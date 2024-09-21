
#include <iostream>
#include "alphabet.h"
#include "symbol.h"


int main() {
  Alphabet simbolo;
  std::cin >> simbolo;
  std::cout << "si" << std::endl;
  std::cout << simbolo << std::endl;
  std::cout << simbolo.GetSize() << std::endl;

}
