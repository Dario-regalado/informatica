#include <iostream>
#include "QEstados.h"
#include "FEstados.h"

int main() {
  QEstados conjunto(0);
  conjunto.Insert(1);
  conjunto.Insert(2);
  conjunto.Insert(3);
  conjunto.Insert(4);
  conjunto.Insert(5);
  std::cout << conjunto << std::endl;

  FEstados conjunto2;
  conjunto2.Insert(1);
  conjunto2.Insert(2);
  conjunto2.Insert(3);
  conjunto2.Insert(4);
  conjunto2.Insert(6);
  std::cout << conjunto2 << std::endl;
  conjunto2.FPerteneceQ(conjunto) ? std::cout << "F esta en Q\n" : std::cout << "F no esta en Q\n";
}