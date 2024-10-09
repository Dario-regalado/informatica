#include <iostream>
#include <vector>

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<bool> numbers(n + 1, false);
    for (int i = 0; i < n - 1; ++i) {
      int num;
      std::cin >> num;
      numbers[num] = true;
    }
    for (int i = 1; i <= n; ++i) {
      if (!numbers[i]) {
        std::cout << i << std::endl;
        break;
      }
    }
  }
  return 0;
}