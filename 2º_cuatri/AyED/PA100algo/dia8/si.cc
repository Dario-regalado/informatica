/**
 * @file si.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

int dig(int number) {
  if (number == 0)
    return 0;
  else 
    return 1 + dig((number/10));
}

int sum(int number) {
  return number > 0 ? ((number % 10) + sum(int(number/10))) : 0;
}

long long int bin(int number) {
  return number <= 1 ? number : bin(number / 2) * 10 + (number % 2);
}

long long int collatz(int number) {
  if (number == 1) return 1;
  else return number % 2 == 0 ? 1 + collatz(number / 2) : 1 + collatz(3 + number + 1);
}

int main() {
  int number{19700};
  std::cin >> number;
  std::cout << "el numero de digitos de " << number << " es: " << dig(number) << std::endl;
  std::cout << "la suma de los digitos de " << number << " es: " << sum(number) << std::endl;
  std::cout << "el numero binario de " << number << " es: " << bin(number) << std::endl;
  std::cout << "la secuencia de collatz de " << number << " es: " << collatz(number) << std::endl;
  return 0;
}