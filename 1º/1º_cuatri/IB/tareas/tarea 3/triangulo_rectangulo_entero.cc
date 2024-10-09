#include <iostream>

int main(const int argc, char *argv[]) {
  int N;
  std::cin >> N;
  
  for (int i = 1; i <= N; ++i) {
    int number_k{0};
    int lado_a{0};
    int lado_b{0};
    int lado_c{0};
    if ( i % 2 == 0) {
      lado_a = i;
      number_k = lado_a / 2;
      lado_b = number_k * number_k - 1;
      lado_c = number_k * number_k + 1;
    } else {
      lado_a = i;
      number_k = (lado_a - 1) / 2;
      lado_b = 2 * number_k * (number_k + 1);
      lado_c = lado_b + 1;
    }
    if ((lado_a <= lado_b) && (lado_b <= lado_c)) {
    std::cout << lado_a << " " << lado_b << " " << lado_c << std::endl;
    }
  }
  return 0;
}
