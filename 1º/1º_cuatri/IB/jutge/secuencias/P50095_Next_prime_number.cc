#include <iostream>

bool IsPrime(int prime);

int NextPrime(int next_prime) {
  if (IsPrime(next_prime)) {
    while (true) {
      ++next_prime;
      if (IsPrime(next_prime)) {
        return next_prime;
      }
    }
  }
}

bool IsPrime(int prime) {
  int repeticiones{0};
  for (int i{1}; i <= prime; ++i) {
    if (prime % i == 0) {
      ++repeticiones;
    }
  }
  return (repeticiones == 2);
}

int main() {
  int prime{};
  while (std::cin >> prime){
    std::cout << NextPrime(prime) << std::endl;
  }
  return 0;
}