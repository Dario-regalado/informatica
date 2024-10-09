#include <iostream>
#include <iomanip>

int main() {
  int N_sequence1{0};
  int N_sequence2{0};
  while (std::cin >> N_sequence1 >> N_sequence2){
    double result1{0.0};
    for (int i = 1; i <= N_sequence1; ++i) {
      result1 += 1.0 / i;
    }
    double result2{0.0};
    for (int i = 1; i <= N_sequence2; ++i) {
      result2 += 1.0 / i;
    }
    std::cout << std::fixed << std::setprecision(10) << result1 - result2 << std::endl;
  } 
  return 0;
}