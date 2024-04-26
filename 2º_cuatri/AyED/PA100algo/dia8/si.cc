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

#include <vector>
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

void GeneraBinario(std::vector<char>& v, const int n){
  if (n == 0) {
    for (int i = v.size(); i >= 0; i--) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl; 
  } 
  else {
    v[n-1] = '0';
    GeneraBinario(v, n-1);
    v[n-1] = '1';
    GeneraBinario(v, n-1);
  }
}

bool Is_PRime(const int n, int divisor) {
  if (n == divisor) return true;
  return (n % divisor == 0) ? false : Is_PRime(n, divisor+1);
}

bool IsPRime(const int n) { 
  return Is_PRime(n, 1);
}

int main() {
  int number{1970};
  //std::cin >> number;
  std::cout << "el numero de digitos de " << number << " es: " << dig(number) << std::endl;
  std::cout << "la suma de los digitos de " << number << " es: " << sum(number) << std::endl;
  std::cout << "el numero binario de " << number << " es: " << bin(number) << std::endl;
  //std::cout << "la secuencia de collatz de " << number << " es: " << collatz(number) << std::endl;

  std::vector<char> numero(5);
  std::cout << std::endl; GeneraBinario(numero, 3);

  std::cout << number << ((IsPRime(number)) ? " no es primo" : " es primo") << std::endl;
  return 0;
}